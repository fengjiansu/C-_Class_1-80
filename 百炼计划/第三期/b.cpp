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
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
struct Node
{
    int index;
    int value;
    int rank;
    Node() : index(0), value(0) {}
    Node(int index, int value) : index(index), value(value) {}
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> r(k), c(k);
    REP(i, 0, k)
    {
        int x, y;
        cin >> x >> y;
        r[i].index = i;
        r[i].value = x;
        c[i].index = i;
        c[i].value = y;
    }
    sort(r.begin(), r.end(), [](const Node a, const Node b)
         { return a.value < b.value; });
    r[0].rank = 1;
    int ra = 2;
    REP(i, 1, k)
    {

        if (r[i].value == r[i - 1].value)
        {
            r[i].rank = r[i - 1].rank;
        }
        else
        {
            r[i].rank = ra;
            ra++;
        }
    }
    sort(r.begin(), r.end(), [](const Node a, const Node b)
         { return a.index < b.index; });
    sort(c.begin(), c.end(), [](const Node a, const Node b)
         { return a.value < b.value; });
    c[0].rank = 1;
    int ca = 2;
    REP(i, 1, k)
    {
        if (c[i].value == c[i - 1].value)
        {
            c[i].rank = c[i - 1].rank;
        }
        else
        {            
            c[i].rank = ca;
            ca++;
        }
    }
    sort(c.begin(), c.end(), [](const Node a, const Node b)
         { return a.index < b.index; });
    REP(i, 0, k)
    {
        cout << r[i].rank << " " << c[i].rank << endl;
    }
    return 0;
}
