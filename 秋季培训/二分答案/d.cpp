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

const double EPS = 1e-6;
/* 
常见的 EPS 设置：
1e-2：用于较低精度要求的问题，如只需保留一位小数。
1e-3：用于保留两位小数的情况。
1e-6：用于大部分常规问题，这通常被认为是默认的“足够精度”。
1e-9 或更小：在某些高精度计算场景下，可能需要设置极小的 EPS，以保证更高的精度。
 */
bool check(double mid,vector<double> &v,vi &s)
{
    double sum = 0;
    int n = v.size();
    REP(i,0,n)
    {
        double vt = v[i]+mid;
        if(vt<=0) return false;
        sum += s[i]/vt;
    }
    return sum<=0.5;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<double> v(4);
    vector<int> s(4);
    REP(i,0,4)
    {
        cin>>v[i];
    }
    REP(i,0,4)
    {
        cin>>s[i];
    }

    double ans=0;
    double r = 50,l = 0;
    while(r-l>EPS)//我们需要通过区间的逐渐缩小来逼近解，而不是像整数那样有明确的分界点
    {
        double mid = l+(r-l)/2.0;
        double sum = 0;
        if(check(mid,v,s))
        {
            ans = mid;
            r = mid; //浮点数更新时不能直接加1,浮点数之间的距离是可以非常小的。我们只需要在区间足够小时停止查找，因此不需要进行离散的步长跳跃更新。
        }
        else
        {
            l = mid;
        }

    }
    cout<<setprecision(2)<<fixed<<ans<<endl;
    return 0;
}
