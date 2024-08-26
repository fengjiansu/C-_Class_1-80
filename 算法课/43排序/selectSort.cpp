#include <bits/stdc++.h>

using namespace std;

int main()
{
   for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[i]) swap(a[i],a[j]);
    }
   }
   return 0;
}
