#include <bits/stdc++.h>

using namespace std;
string s1,s2,s3;
int main()
{
   cin>>s1>>s2>>s3;
   //s1 s2 s3 从小到大输出
   if(s1>s2)
   {
     string temp;
     temp=s1;
     s1=s2;
     s2=temp;
   
   }
   else if(s1>s3)
   {
     string temp;
     temp=s1;
     s1=s3;
     s3=temp;
   }
   else if(s2>s3)
   {
     string temp;
     temp=s2;
     s2=s3;
     s3=temp;
   }
   cout<<s1<<endl<<s2<<endl<<s3<<endl;
   return 0;
}
