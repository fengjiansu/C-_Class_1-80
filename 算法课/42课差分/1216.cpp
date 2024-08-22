#include <bits/stdc++.h>

using namespace std;

int main()
{
   //体积大的鱼先吃 要么剩1条 要么都在 
   int n;
   cin>>n;
   vector<int> a(n);
   bool f = false;
   cin>>a[0];
   int pre = a[0];
   for(int i=1;i<n;i++)
   {
    cin>>a[i];
    if(pre != a[i])
    {
        f = true;
    }
    
   }
   if(f)
   {
    cout<<1;
   }
   else
   {
    cout<<n;
   }
   
   return 0;
}
