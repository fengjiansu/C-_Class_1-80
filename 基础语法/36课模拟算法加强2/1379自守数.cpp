/* 
C. ������
����

���ĳ����k��ƽ������n�Ժ�,�����ĩβ��λ������k,��ô�ͳ������Ϊ��n-����
����������3��922=25392,��25392��ĩβ��λ������92,����92��һ��3-��
������
����������д�����ж�һ�������������Ƿ����ĳ��n��n-��������

����

����һ��������k

���

�������n-����������һ���������С��n��nk2��ֵ,�������nO

 */
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
int wei(int k)
{
    int w = 0;
    while(k)
    {
        k/=10;
        w++;
    }
    return w;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    ll res;
    int w = wei(k);
    REP(i,1,11)
    {
        res = pow(k,2)*i;// pow�ķ���ֵ��double
        //����k�ĳ��� to_string(k).length()
        // to_stirng(k); c++11 �����ֻ��������°汾��C++ Ҳ�᲻�ϵظ��£��ó�����Ʊ�ø��򵥡���ǿ�󡣰������͸�����ת��Ϊ�ַ��� ������ת�����ܲ�׼ȷ
        if(res%(ll(pow(10,w))) == k)
        {
            cout<<i<<" "<<res;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}
