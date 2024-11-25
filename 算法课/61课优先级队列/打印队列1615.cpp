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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,top;cin>>n>>top;
    vector<int> v(n); //存储 id和优先级
queue<int> q;//存储 id
priority_queue<int> pq;//存储优先级
    for(int i=0;i<n;i++) 
    {cin>>v[i];
        q.push(i);
        pq.push(v[i]);
    }
    int cnt = 0;
    while(!q.empty())//q不空代表没打印完
    {
        int id = q.front();q.pop();//注意queue调用的是front
        while(v[id]!=pq.top())
        {
            q.push(id);
            id = q.front();q.pop();
        }
        cnt++;
        pq.pop();
        if(id == top) break;
        
    }
    cout<<cnt;
    
    return 0;
}
