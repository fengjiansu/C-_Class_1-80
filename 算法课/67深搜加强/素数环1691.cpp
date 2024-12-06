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
������ �����Ǹ��� ,������Ȼ���Կ�����������,��һ�����ֺ���һ������֮��������,�����ù������ֲ�������,
ĩβ�����ֺ͵�һ�����ֵĺ�ҲҪ�����ж�
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

    for (int i = 2; i <=  n; i++)//��1��ʼ,�����һ��λ��һ����1,���Ժ���ֻ��ö��2-n
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
