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
int f= 0;
bool empty()
{
    return f >= a.size();
}
void push(int    x)
{
    a.push_back(x);
}
void pop()
{
    if(!empty())
    {
        f++;
    }
}
void front()
{
    if(!empty())
    {
        cout<<a[f]<<"\n";
    }
    else
    {
        cout<<"empty\n";
    }
}
void back()
{
    if(!empty())
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
    cout<<a.size()-f<<"\n";
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
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
        else if(s=="front")
        {
            front();
        }
        else if(s=="back")
        {
            back();
        }
        else if(s=="size")
        {   
            size();
        }
    }
    return 0;
}
