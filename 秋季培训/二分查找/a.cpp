#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    REP(i,1,n+1)
    {
        cin>>a[i];
    }
    int t;
    cin>>t;
    if(a[n]<t)
    {
        cout<<"no answer"<<endl;
        return 0;
    }
    int l = 1,r = n;
    while(l<r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]>=t)
        {
            r = mid;
        }
        else
        {
            l = mid +1;
        }
    }
    cout<<l;
    return 0;
}
