#include <bits/stdc++.h>

using namespace std;

int main()
{
   
   int n,u,d;
   cin>>n>>u>>d;
   if(n<=u)
   {
       cout<<1<<endl;
   }
   else
   {
    /*
    12 3 1
    x = (12-3)/(3-1)= 9/2 = 4.5 
     */
     int x = ceil((n-u)*1.0/(u-d));
     cout<<2*x+1<<endl;
   }
   return 0;
}
