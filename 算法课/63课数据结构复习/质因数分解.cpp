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


/* 
�������ֽ⣨Prime Factorization���ǽ�һ����������ʾΪ���������ĳ˻��Ĺ��̡�

������ֻ�ܱ� 1 �������������������� 2, 3, 5, 7, 11 �ȡ�
��������һ������������������������������
������
36 ���������ֽ�Ϊ��
36 = 2^2 \times 3^2 ] ���2 �� 3 �� 36 ������������ָ���ֱ�Ϊ 2��

84 ���������ֽ�Ϊ��
84 = 2^2 \times 3^1 \times 7^1 ] ���2��3��7 ������������

�������ֽ�Ĺ���
����Ҫ��һ���� n=84 �����������ֽ⣺

����С������ 2 ��ʼ��84��2=42������ 2 ��һ����������
�ٴγ��� 2��
42��2=21��
21 �����ٱ� 2 ���������Ի���һ������ 3��
21��3=7������ 3 ��һ����������
7 ����������ֻ�ܱ�����������
7��7=1��
�������ֽ���ɣ�
84=2^2*3^1*7^1��

 */
map<int, int> fun(int n)
{
    map<int, int> res;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
            
        }
    }
    // n����ҲҪ����
    if (n > 1)
    {
        res[n] = 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 84;
    map<int,int> res;
    res = fun(n);
    for(auto &it:res)
    {
        cout<<it.first<<":"<<it.second<<endl;
    }
    return 0;
}
