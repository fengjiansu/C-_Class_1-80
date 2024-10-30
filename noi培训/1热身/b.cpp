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
string fun(string  s,string t)
{
    int maxLen = max(s.size(), t.size());
    while (s.size() < maxLen) s.insert(0, "0");
    while (t.size() < maxLen) t.insert(0, "0");
    string ans = "";
     char carry = '0';
    for (int i = maxLen - 1; i >= 0; i--) {
        int sum = (s[i] - '0') + (t[i] - '0') + (carry - '0');
        ans += (sum % 2) + '0';
        carry = (sum / 2) + '0';
    }
    if (carry == '1') ans += carry; //二进制加法中，如果 sum >= 2，则需要进位 1
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    string s1 = s;
    REP(i,0,16)
    {
        s1 = fun(s1,s);
    }
    cout<<s1<<endl;
    return 0;
}
