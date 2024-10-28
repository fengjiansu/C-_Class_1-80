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
    int n,m;
    cin>>n>>m;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(s.find(x)!=s.end())
        {
            cout<<x<<endl;
        }
    }
    return 0;
}
