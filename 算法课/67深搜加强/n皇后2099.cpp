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
/*
n�ʺ�����
�������뵽 ������ת��Ϊ��n*n��������ѡ��n������
����C(2N,N)�����`
�Խ��� ��ƽ����

��Ϊÿ��ÿ�и�����1���ʺ� ,�� A[x]��ʾ��x�лʺ���еı��
��ô�ͱ����һ��ȫ��������

���Խ�����y-x��ʾ���ζԽ�����y+x��ʾ
 */
int cnt = 0;
int num = 0;
bool b[20];
void dfs(vi &A, int n)
{
    if (A.size() == n)
    {
        if (num < 3)
        {
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i]+1 << " ";
            }
            cout << endl;
        }

        cnt++;
        num++;
        return;
    }
    //int x = A.size() ? A.back() + 1 : 1;
    for (int i = 0; i < n; i++)
    {
        /*
        ��Ϊ�Ǻ��ű����� ����ͬһ�е�����Ͳ����ж�
        �ж� ͬһ��
        ͬһ���Խ���
        ͬһ���Խ���
         */
        bool f = false;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] == i || A[j] - j == i - A.size() || A[j] + j ==  i+A.size())
            {
            	f = true;
                break;
                
            }
        }
        if (f)
            continue;
        if(b[i]) continue; // ����Ҫ ��Ϊ��ȥ�ж�ÿһ�в����ظ���
        b[i] = true;
        A.push_back(i);
        dfs(A, n);
        A.pop_back();
        b[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi A;
    dfs(A, n);
    cout << cnt;
    return 0;
}
