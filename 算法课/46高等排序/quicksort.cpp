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
const int N = 1e5 + 5;
int a[N];
void quicksort(int l, int r) {
    if(l>=r) return;
    int i = l, j = r,x=a[l];
    while(i<j) {
        while(i<j && a[j]>=x) j--;
        a[i] = a[j];
        while(i<j && a[i]<=x) i++;
        a[j] = a[i];
    }
    a[i] = x;
    quicksort(l,i-1);
    quicksort(i+1,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    REP(i,0,n) cin>>a[i];
    quicksort(0,n-1);
    REP(i,0,n) cout<<a[i]<<" ";
    return 0;
}
