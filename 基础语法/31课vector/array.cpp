#include <bits/stdc++.h>

using namespace std;
int a[100000000];
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   // ��a[3]�в���һ��Ԫ��
   /* //a[3]=100;
   for(int i=3;i<n+1;i++)
   {
    a[i+1] = a[i];
   }
   a[3] = 100;
   //ɾ��a[3]
   for(int i=3;i<n;i++)
   {
    a[i] = a[i+1];
   } */

   //vector ��ʼ������
   vector<T> v1; //v1��һ����vector,��Ǳ�ڵ�Ԫ����T���͵�,ִ��Ĭ�ϳ�ʼ��

vector<T> v2(v1); //v2�а�����v1����Ԫ�صĸ���

vector<T> v2 = v1; //�ȼ���v2(v1),v2�а�����v1����Ԫ�صĸ���

vector<T> v3(n, val);//v3������n���ظ���Ԫ��,ÿ��Ԫ�ص�ֵ����val
vector<T> v4 (n);//v4������n���ظ���ִ����ֵ��ʼ���Ķ���
vector<T> v5{a,b, c ... };//v5�����˳�ʼֵ������Ԫ��,ÿ��Ԫ�ر�������Ӧ�ĳ�ʼֵ
vector<T> v5={a,b, c ... };//�ȼ���v5{a,b,c ... }









   return 0;
}
