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
    cout.tie(0);
    int n,a;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    for(auto &it:s)
    {
        cout<<it<<" ";
    }
    return 0;
}