#include <bits/stdc++.h>
using namespace std;
int fun(string s)
{
    string res;
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
    	string temp="";
        if(isdigit(s[i]))
        {
           while(i<s.size()&&isdigit(s[i]))
           {
           		temp.push_back(s[i]);
           		i++;
		   }
		   st.push(stoi(temp));
        }
        else if(s[i]=='@')
        {
     		break;
        }    
        else 
        {
        	int b=st.top(); st.pop();
        	int a=st.top(); st.pop();
        		if(s[i]=='+')
        	{
        		st.push(a+b);
			}
				
				if(s[i]=='-')
        	{
        		st.push(a-b);
			}
				if(s[i]=='*')
        	{
        		st.push(a*b);
			}
				if(s[i]=='/')
        	{
        		st.push(a/b);
			}
		}       

}
    return st.top();
}