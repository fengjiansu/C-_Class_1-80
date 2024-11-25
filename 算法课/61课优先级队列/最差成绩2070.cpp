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

struct student{
    string name;
    int c,m,e;
    int sum;
    student(){
        c = 0; m = 0; e = 0;
    }
    student(string n,int a,int b,int c):name(n),c(a),m(b),e(c),sum(a+b+c){}
    bool operator<(const student& other) const {
        
        return sum > other.sum;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    priority_queue<student> q;
    REP(i,0,n)
    {
        string a;cin>>a;
        int c,m,e;cin>>c>>m>>e;
        student s(a,c,m,e);
        q.push(s);
        cout<<q.top().name<<"\n";
    }
    return 0;
}
