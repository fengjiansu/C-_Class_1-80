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
const int N = 1e5 + 5;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    for(auto&c:s)
    {
        if(isupper(c)) c = tolower(c);
        a[c-'a']++;
    }
    sort(a,a+26);
    int sum = 0;
    for(int i=0;i<26;i++)
    {
        sum += a[i] * (i+1);
    }
    cout<<sum;
    return 0;
}
