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
    int n;cin>>n;
    cout<<(n+1)/2<<"\n";
    priority_queue<int> max_p;
    priority_queue<int,vector<int>,greater<int>> min_p;
    REP(i,0,n)
    {
        int x;cin>>x;
        //插入数据
        if(max_p.empty()||x<max_p.top())
        {
            max_p.push(x);
        }
        else
        {
            min_p.push(x);
        }
        //维护两个堆的平衡
        if(max_p.size()>min_p.size()+1)
        {
            min_p.push(max_p.top());
            max_p.pop();
        }
        else if(min_p.size()>max_p.size())
        {
            max_p.push(min_p.top());
            min_p.pop();
        }
        //输出中位数
        if(max_p.size()==min_p.size())
        {
            //cout<<(max_p.top()+min_p.top())/2<<" ";
        }
        else
        {
            cout<<max_p.top()<<" ";
        }
    }
    return 0;
}
