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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int n_o=0,n_l=0;
    for(auto&c:str)
    {
        if(c=='O')
        {
            n_o++;
        }
        else
        {
            n_l++;
        }
    }
    pair<int,int> newo,newl;
    newo=MP(0,n_o);
    newl=MP(0,n_l);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='O')
        {
            newo.F++;
            newo.S--;
        }
        else
        {
            newl.F++;
            newl.S--;
        }
        if(newo.F!=newo.S&&newl.F!=newl.S)
        {
            cout<<i+1;
            return 0;
        }
        
    }
    cout<<-1;

    return 0;
}
