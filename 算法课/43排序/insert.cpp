#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {1,2,2,5,5,9,9,3,3};
    int n = a.size();
    int temp,j;
   /* for(int i = 1; i<n; i++)
   {

       temp = a[i];
       //�������Ԫ�ز��뵽��ȷ��λ��
       // ��i-1�� 0 �ҵ�һ����tempС����
       for(j = i-1; j>=0 && a[j]>temp; j--)
       {
           a[j+1] = a[j];
       }
       a[j+1] = temp;
   } */
  // [1,n-1]δ��������
   for(int i= 1;i<n;i++)
   {
    //��ǰ�����������Ļ� ����������[0,i-1]
    // 1 3 3 5 5 2 2
       for(j = 0; j<i ;j++)
       {
           if(a[j]>a[i])
           {
            swap(a[j],a[i]);
           }
       }
   }
   for(auto x:a)
   {
    cout<<x<<" ";
   }
   return 0;
}
