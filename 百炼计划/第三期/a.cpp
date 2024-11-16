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
struct Node{
    int index;
    int value;
    Node():index(0),value(0){}
    Node(int index,int value):index(index),value(value){}
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vector<Node> a(n);
    REP(i,0,n) { a[i].index = i; cin>>a[i].value; }
    sort(a.begin(),a.end(),[](const Node a,const Node b){return a.value>b.value;});
    cout<<a[1].index+1<<endl;
    return 0;
}
