#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> b(n,0);
   int l,r;
   for(int i=0;i<m;i++)
   {
        cin>>l>>r;
        l--;
        r--;
        b[l] += 1;
        if(r+1<n)
            b[r+1] -= 1;
   }
   int sum = 0;
   for(int i=0;i<n;i++)
   {
        sum += b[i];
        cout<<sum<<" ";
   }
   return 0;
}
