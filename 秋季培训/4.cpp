#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
struct person
{
    int id;
    int score;
    int rank;
    bool operator<(const person &other) const
    {
        return score < other.score;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, g;
    cin >> n >> g;
    vector<person> v(n);
    priority_queue<person> q;
    REP(i, 0, n)
    {
        cin >> v[i].score;
        v[i].id = i;
    }
    REP(i, 0, n)
    {
        int x;
        cin>>x;
        q.push(v[x]);
    }
    int sum = n;
    while(q.size()>1)
    {
        
    }


    return 0;
}
