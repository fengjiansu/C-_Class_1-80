#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s;
   getline(cin,s);
   int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' '&&s[i]!='\n')
        {
            cnt++;
        } 
    }
    cout<<cnt;
   return 0;
}
