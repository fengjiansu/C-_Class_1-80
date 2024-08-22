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
   // 往a[3]中插入一个元素
   /* //a[3]=100;
   for(int i=3;i<n+1;i++)
   {
    a[i+1] = a[i];
   }
   a[3] = 100;
   //删除a[3]
   for(int i=3;i<n;i++)
   {
    a[i] = a[i+1];
   } */

   //vector 初始化方法
   vector<T> v1; //v1是一个空vector,它潜在的元素是T类型的,执行默认初始化

vector<T> v2(v1); //v2中包含有v1所有元素的副本

vector<T> v2 = v1; //等价于v2(v1),v2中包含有v1所有元素的副本

vector<T> v3(n, val);//v3包含了n个重复的元素,每个元素的值都是val
vector<T> v4 (n);//v4包含了n个重复地执行了值初始化的对象
vector<T> v5{a,b, c ... };//v5包含了初始值个数的元素,每个元素被赋予相应的初始值
vector<T> v5={a,b, c ... };//等价于v5{a,b,c ... }









   return 0;
}
