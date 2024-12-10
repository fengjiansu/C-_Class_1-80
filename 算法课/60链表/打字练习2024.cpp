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
const int MAXN = 1e5 + 10;
bool vis[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='@')
        {
            vis[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(!vis[j])
                {
                    vis[j]=1;
                    break;
                }
            }
        }
    }
    REP(i,0,str.size())if(!vis[i])cout<<str[i];
    return 0;
}
