/* 

��Ŀ����
����һ���ַ���,�ڵ�k���ַ������һ�澵��,�ַ���
�ͻ���S1S2S3 ... Sk-1SkSkSk-1 .. S3S2S1������ʽ��
�ʷ��꾵�Ӻ��ܿ������ֵ�����С���ַ�����
a ���ֵ����bС,����:
�� a��b��ǰ׺��azb;
�� ��ͬλ��,a��һ����b��ͬ���ַ�����ĸ�����ȳ��֡�

����
һ��������t,��ʾt���������,������10000�顣����
��t���������,ÿ�����ݵ�һ��һ��������n,������һ
�г�Ϊn���ַ���,n������100000��

���
t��,ÿ��һ���������Ҫ����ַ�����

(1804) Mirror in the String

��������
4
10
codeforces
9
cbacbacba
3

aaa
4
bbaa

�������
CC
cbaabc
aa
bb
 */


#include <bits/stdc++.h>

using namespace std;

void solve()
{
        int n;
        string s;
        cin >> n >> s;
        /* 
        codeforces
        cc 
        cbaabc
        ��k+1���ַ�С��k���ַ�ʱ��������
        
        aaa   aa
        bbaa  bb
        ��2���ڵ�һ���ַ����ʱ �ڵ�һ���ַ���Ӿ���
        �������Ҫ�Լ��뵽
        cbbaaab
        cbbaabbc cbbaaaabbc
        ���ַ����ʱ�Ҳ�����λ����������ֱ�������һ���ַ����ڵ�ǰ�ַ�

        
         */
        int k = 0; // ��ʼk��λ��
        for (int i = 1; i < n; ++i) {
            if(s[i]<s[i-1]|| (s[i]==s[i-1]&&i!=1))
            {
                k = i;
            }
            else{
                break;
            }
        }
        for(int i = 0; i <= k; ++i)
        {
            cout << s[i];
        }
        for(int i = k; i >=0; i--)
        {
            cout << s[i];
        }
        cout << endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    solve();
   }
   return 0;
}
