#include <bits/stdc++.h>
using namespace std;

int main()
{
   unordered_set<string> se;
   int n;
   cin>>n;
   while(n--)
    {
        string s;
        cin>>s;
        se.insert(s);
    }
    cout<<52-se.size();
   return 0;
}
