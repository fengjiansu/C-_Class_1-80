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
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
/* 
素数环 看似是个环 ,但是仍然可以看作排列问题,下一个数字和上一个数字之差是素数,而且用过的数字不能再用,
末尾的数字和第一个数字的和也要进行判断
 */
bool b[20];
void dfs(vector<int> &A)
{
    if (A.size() == n)
    {
        if(isPrime(A[0]+A.back()))
        {
            for (auto &it : A)
            cout << it << " ";
        cout << "\n";
        }
        return;
    }

    for (int i = 2; i <=  n; i++)//从1开始,代表第一个位置一定是1,所以后面只能枚举2-n
    {
        /* if (i == A.size() + 1)
            continue; */
        if(!isPrime(A.back()+i))
        {
            continue;
        }
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
    A.push_back(1);
    dfs(A);
    return 0;
}
