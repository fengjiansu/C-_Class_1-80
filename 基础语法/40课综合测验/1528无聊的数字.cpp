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

int wei(int x)
{
    int wei = 0;
    while(x)
    {
        x/=10;
        wei++;
    }
    return wei;
}
void solve()
{
    int x;
    cin>>x;
    //获取最高位的数字
    int a=x%10;
    int pre = (a-1)*10;
    int w = wei(x);
    int sum = (w+1)*(w)/2;
    cout<<pre+sum<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
