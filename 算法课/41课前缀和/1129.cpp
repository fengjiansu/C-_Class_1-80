/* 
��Ŀ����

(1129)���������

����һ������Ϊn����������A1,A2,��,An,����������͡����仰˵,Ҫ�ҵ�1��i��j
��n,ʹ��Ai+Ai+1+ ... +Aj������

����
��һ���������г���n,n��105���ڶ�����������n������(��Χ-1000~1000)��

���
һ������,��������͡�

��������
8
1 -3 7 -5 8 -3 -2 6

�������
11
 */
#include <bits/stdc++.h>

using namespace std;
int a[100005];
int pre[100005];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    pre[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
/* 
 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            sum += pre[j] - pre[i-1];
        }
    }
 */

      int maxSum = pre[0];  // ����
    int minSum = 0;       // ǰ׺�͵���Сֵ����ʼΪ0��

    for (int j = 0; j < n; j++) {
        maxSum = max(maxSum, pre[j] - minSum); //ÿ�μ��� pre[j] - minSum�������ֵ��ʾ�� j ��β���������������͡�
        minSum = min(minSum, pre[j]);
    }

    cout << maxSum << endl;
    return 0;
}
