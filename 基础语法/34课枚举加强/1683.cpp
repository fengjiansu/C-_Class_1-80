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
int x[15];
void fun(int a)
{
    while (a)
    {
        x[a % 10]++;
        a /= 10;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    �б�����ϵ a b c ����ֻö��a 2a 3a
    a 0-1000 3a 0-1000 a <= 333
    ��λ��ÿλ���ֲ�ͬ
    a>=123 a<=329
     */
    bool flag = 1;
    for (int a = 123; a <= 329; a++)
    {
        /*
        �ж� a 2a 3a ÿλ���Ƿ��1-9���õ���
        ���Խ���Ͱ˼��
        */
        // �� x��0
        memset(x, 0, sizeof(x));
        fun(a);
        fun(2*a);
        fun(3*a);
         flag = 1;
        for (int i = 1; i <= 9; i++)
        {
            if (x[i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << a << " " << 2 * a << " " << 3 * a << endl;
    }
    return 0;
}