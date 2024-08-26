#include <bits/stdc++.h>

using namespace std;

int main()
{
   //排序 之后求和
   int n,b;
   cin>>n>>b;
   vector<int> a(n);
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   sort(a.begin(),a.end());
   int sum = 0;
   for(int i=n-1;i>=0;i--)
   {
       sum+=a[i];
       if(sum>=b)
       {
           cout<<n-i<<endl;
           return 0;
       }
   }
   return 0;
}
