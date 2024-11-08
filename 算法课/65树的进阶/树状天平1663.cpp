#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
bool flag = true;
int goDown()
{
    int wl,dl,wr,dr;
    cin>>wl>>dl>>wr>>dr;
    if(wl == 0)
    {
        wl = goDown();
    }
    if(wr == 0)
    {
        wr = goDown();
    }
    if(wl*dl != wr*dr) flag = false;
    return wl+wr;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    goDown();
    if(flag)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}