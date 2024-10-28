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
    int n,x;
    cin>>n>>x;
    vi a(n+1);
    vi s(n+1,0);
    REP(i,1,n+1)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    map<int,int> mp;
    for(int k = 1;k<n;k++)
    {
        
        REP(i,1,n-k+2)
        {
            if(s[i+k-1]-s[i-1]==x)
            {
               
                //cout<<"l: "<<i<<"r: "<<i+k<<endl;
                mp.insert(MP(i,i+k-1));
            }
        }
    }
    for(auto i:mp)
    {
        cout<<i.F<<" "<<i.S<<endl;
    }
    return 0;
}
