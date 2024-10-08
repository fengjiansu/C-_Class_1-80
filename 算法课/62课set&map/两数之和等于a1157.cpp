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
    int n;
    cin >> n;
    map<int, int> mp;
    int num;
    for(int i = 1; i < n+1; i++)
    {
        cin>>num;
        mp[num] = i;
    }
    int a;
    cin>>a;
    bool flag = false;
    for(auto &x: mp)
    {
        if(mp.find(a-x.F) != mp.end())
        {
            cout<<x.S<<" "<<mp[a-x.F]<<endl;
            flag = true;
        }
    }
    if(!flag) 
    {
        cout<<"no"<<endl;
    }
    return 0;
}