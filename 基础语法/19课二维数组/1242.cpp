/* 
��Ŀ����
(1242)�Խ������
����һ������Ϊn�������ξ���,�����������Խ��������ֵĺ͡�
����
��һ��һ������n(1��n��100)��
������һ��n��n�еľ���(�����е�ÿ�������ڵ���0��С�ڵ���100)��
���
���һ��������ʾ�𰸡�
��������
3
111
111
111
�������
5
 */
#include <bits/stdc++.h>

using namespace std;

int a[105][105];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    /* for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j || i + j == n - 1)
            {
                sum += a[i][j];
            }
        }
    } */
    //�Ӱ༶�����������������
    for (int i = 0; i < n; i++)
    {
       sum += a[i][i] +a[i][n - i - 1];
    } 

   if(n%2)
   {
       sum -= a[n/2][n/2];
   }
   cout<<sum;
   return 0;
}
