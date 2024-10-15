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

vector<int> a;
void push(int    x)
{
    a.push_back(x);
}
void pop()
{
    if(!a.empty())
    {
        a.pop_back();
    }
}
void top()
{
    if(!a.empty())
    {
        cout<<a.back()<<"\n";
    }
    else
    {
        cout<<"empty\n";
    }

}
void size()
{
    cout<<a.size()<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        if(s=="push")
        {
            int x;
            cin>>x;
            push(x);
        }
        else if(s=="pop")
        {
            pop();
        }
        else if(s=="top")
        {
            top();
        }
        else if(s =="size")
        {
            size();
        }
    }
    return 0;
}
