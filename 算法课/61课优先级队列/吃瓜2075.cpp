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
// priority_queue<int,vector<int>,greater<int>> q;
/*
空格的历史问题讲一下
 */
struct Person
{
    int id;
    int score;
};

struct cmp//比较器 类
{

    bool operator()(Person a, Person b)
    {
        return a.score > b.score;
    }
}; 
priority_queue<Person, vector<Person>, cmp> q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> q;
    REP(i, 0, n)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    REP(i, 0, n)
    {

        int x;
        cin >> x;
        cout << q.top() << "\n";
        q.pop();
        q.push(x);
    }

    return 0;
}
