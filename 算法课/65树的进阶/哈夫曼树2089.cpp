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

//每次选取两个最小的数,求和,新产生的数加入原序列,依然保持
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

//每次选取两个最小的数,求和,新产生的数加入原序列,依然保持
priority_queue<int, vector<int>, greater<int>> pq;

int n, sum, a, x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i <n - 1; i++)
    {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        sum += x + y;
        pq.push(x + y);

        
    }
    cout << sum << endl;
        return 0;
}


int n, sum, a, x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i <n - 1; i++)
    {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        sum += x + y;
        pq.push(x + y);

        
    }
    cout << sum << endl;
        return 0;
}
