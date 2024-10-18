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

struct person
{
    int id;
    int score;
    int cost;
    bool operator<(const person& other) const
    {
        if(score == other.score)
        {
            return  cost< other.cost;
        }
        return score > other.score;

    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<person> v(n);
    set<int> s;
    REP(i,0,n)
    {
        v[i].id = i+1;
        cin>>v[i].score>>v[i].cost;
    }
    sort(v.begin(),v.end());
    int min_cost = v[0].cost;
    for(auto& vi:v)
    {        
        if(vi.cost <= min_cost)
        {
            s.insert(vi.id);
            min_cost = vi.cost;
        }
        
    }
    cout<<s.size()<<"\n";
    for(auto &si:s)
    {
        cout<<si<<" ";
    }
    return 0;
}
