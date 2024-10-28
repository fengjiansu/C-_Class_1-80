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
struct Node
{
list<int>::iterator left, right;
int diff;
bool operator<(const Node& other) const {
    return diff > other.diff;
}
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n+1);
    REP(i,1,n+1)
    {
        a[i].F=i;
        a[i].S = i;
    }
    REP(i,0,k)
    {
        int x;
        cin>>x;
        a[x].S = 0;
    }
    vector<int> c;
    REP(i,1,n+1)
    {
        if(a[i].F-a[i].S!=0)
        c.push_back(a[i].F-a[i].S); ;
    }
    int r = 0;
    if(c.size()==0)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(c.begin(),c.end());
    list<int> l(c.begin(),c.end());
    priority_queue<Node> q;
    int r = 0;
    for(auto it = l.begin();it!=l.end();it++)
    {
        Node node;
        node.left = it;
        node.right = next(it);
        node.diff = abs(*it - *(next(it)));
        q.push(node);
    }

    while(q.size()>1)
    {
        Node node = q.top();
        q.pop();
        
        // 如果左右两人已不再相邻，跳过该配对
        if (next(node.left) != node.right) continue;
        r += node.diff ;

        auto new_left = (node.left==l.begin()?l.end():prev(node.left));
        auto new_right = next(node.right);
        l.erase(node.left);
        l.erase(node.right);

        /* if(new_left!=l.end()&&new_right!=l.end())
        {

        } */

    }
    cout<<r;

    return 0;
}
