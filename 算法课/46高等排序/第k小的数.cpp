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
const int N = 5e6 + 5;
int a[N];
int quicksort(int l, int r,int k) {
    if(l>=r) return a[l];
    int i = l, j = r,x=a[l];
    while(i<j) {
        while(i<j && a[j]>=x) j--;
        a[i] = a[j];
        while(i<j && a[i]<=x) i++;
        a[j] = a[i];
    }
    a[i] = x;
    if(i-l>=k) return quicksort(l,i-1,k);
    else if(i-l+1==k) return x;
    else return quicksort(i+1,r,k-i+l-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    REP(i,0,n) cin>>a[i];
    cout<<quicksort(0,n-1,k)<<endl;
    return 0;
}
