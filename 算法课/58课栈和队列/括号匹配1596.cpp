#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    if(s.length()%2!=0)
    {
        cout<<"no\n";
        return 0;
    }
    if(s.length()==0)
    {
        cout<<"yes\n";
        return 0;
    }
    stack<char> st;
    REP(i,0,s.length())
    {
        if(s[i]=='('||s[i] =='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                cout<<"no\n";
                return 0;
            }
            else
            {
                if((s[i]==')' && st.top()=='(')||(s[i]==']' && st.top()=='['))
                {
                    st.pop();
                }
                else
                {
                    cout<<"no\n";
                    return 0;
                }
            }
        }
        
    }
    if(!st.empty())
    {
        cout<<"no\n";
    }
    else
{
    cout<<"yes\n";
}
    return 0;
}
