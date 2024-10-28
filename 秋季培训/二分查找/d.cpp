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
    int n,c;
    cin>>n>>c;
    vi v(n);
    REP(i,0,n)
    {
        cin>>v[i];
    }
    unordered_map<int,int> mp;
    REP(i,0,n)
    {
        mp[v[i]]++;
    }
    int res = 0;
    REP(i,0,n)
    {
        if(mp.find(c+v[i])!=mp.end())
        {
            res += mp[c+v[i]];
        }
       /* if(mp.find(v[i]-c)!=mp.end())
        {
            res+= mp[c];
        }*/
    }
    cout<<res<<endl;
    return 0;
}