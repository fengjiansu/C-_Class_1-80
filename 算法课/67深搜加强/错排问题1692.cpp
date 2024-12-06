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
int n;
void dfs(vector<int> &A)
{
    if (A.size() == n)
    {
        for (auto &it : A)
            cout << it << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <=  n; i++)
    {
        if (i == A.size() + 1)
            continue;
        bool ok = 1;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] == i)
                ok = 0;
        }
        if (ok)
        {
            A.push_back(i);
            dfs(A);
            A.pop_back();
        }
    }
}
bool b[10];
void dfs_1(vector<int> &A)
{
    if (A.size() == n)
    {
        for (auto &it : A)
            cout << it << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <=  n; i++)
    {
        if (i == A.size() + 1)
            continue;
        if (b[i]==0)
        {
            b[i]=1;
            A.push_back(i);
            dfs(A);
            A.pop_back();
            b[i]=0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> A;
    dfs(A);
    return 0;
}
