#include <bits/stdc++.h>

using namespace std;
bool fun(int t)
{
    if(t%7 == 0)
    {
        return true;
    }
    while(t)
    {
        if(t%10 == 7)
        {
            return true;
        }
        t/=10;
    }
    return false;
}
int main()
{
   int n,m,t;
   cin>>n>>m>>t;
   vector<string> s;
   for(int i=0;i<n;i++)
   {
       string str;
       cin>>str;
       s.push_back(str);
   }
   deque<string> dq;
   m = m-1;//下标从0开始的话注意
   for(int i=0;i<n;i++)
   {
      dq.push_back(s[m%n]);
      m++;
   }
   while(dq.size() !=1)
   {
    if(fun(t))
    {
        dq.pop_front();
    }
    else
    {
        dq.push_back(dq[0]);
        dq.pop_front();
        
    }
    t++;
   }
   cout<<dq[0];
   return 0;
}
