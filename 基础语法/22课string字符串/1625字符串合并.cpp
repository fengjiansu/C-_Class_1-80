#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s3="";
    cin>>s1>>s2;
    //讲下条件运算符
    s3 += s1<s2?s2+s1:s1+s2;
    for(int i=0;i<s3.size();i++)
    {
        if(i%2)
        {
            cout<<s3[i];
        }
    }
   return 0;
}

