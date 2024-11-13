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

void fun(int n)
{
    if(n == 1) {cout<<'X';return;}
    fun(n-1);
    REP(i,0,pow(3,n-2)) cout<<' ';
    fun(n-1);
    cout<<"\n";
    REP(i,0,pow(3,n-2)) cout<<' ';
    fun(n-1);
    REP(i,0,pow(3,n-2)) cout<<' ';
    cout<<"\n";
    fun(n-1);
    REP(i,0,pow(3,n-2)) cout<<' ';
    fun(n-1);
    cout<<"\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fun(3);
    return 0;
}
