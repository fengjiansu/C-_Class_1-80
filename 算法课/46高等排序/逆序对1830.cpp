#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
const int N=1e5+5;
int n,a[N],tmp[N]; 
ll ans;

void merge(int l,int r)
{
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j])tmp[k++]=a[i++];
		else
		{
			tmp[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
    while(i<=mid)tmp[k++]=a[i++];
    while(j<=r)tmp[k++]=a[j++];
    for(int i=l;i<=r;i++)a[i]=tmp[i];
}

void mergesort(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,r);
}
int main(){
	cin >> n  ;
	for(int i=1;i<=n;i++)cin >> a[i];
	mergesort(1,n);
	cout<<ans<<endl;
	
	return 0;
}