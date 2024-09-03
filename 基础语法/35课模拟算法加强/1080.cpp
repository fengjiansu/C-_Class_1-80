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
    cout.tie(0);
    ll a,b,k;
    cin>>a>>b>>k;
    // a/b化为小数后,第k项小数的值
    //模拟竖式除法
    int ans = 0;
    a %= b; // 整数部分不算
    while(k--)
    {
        ans = a*10/b;
        a = a*10%b;
    }
    cout<<ans;
        /* // a/b化为小数后,第k项小数的值

    }
    /* // a/b化为小数后,第k项小数的值
    // a*pow(10,k)表示把a的小数点向右移动k位
    // 然后除以b,就可以把小数点向左移动k位
    // 例如a=12,b=3,k=2
    // 12*pow(10,2) = 1200
    // 1200/3 = 400
    // 400%10 = 0
    ll  ans = a*pow(10,k)/b;
    cout<<ans%10<<endl; */

    return 0;
}
