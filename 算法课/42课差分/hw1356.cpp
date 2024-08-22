#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    int sum = 0;
    cin>>x;
    int i;
    for( i=1;sum<x;i++)
    {
        sum+=i;
    }
    if(sum-x==1) i++;
    cout<<i-1;
   return 0;
}
