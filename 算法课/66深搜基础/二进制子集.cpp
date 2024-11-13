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
/* 
从右往左表示子集，使得每一位对应的元素编号和二进制数的权值顺序一致

 */

void print_subset(int n, int s)//把s代表的二进制数的子集输出
{
    REP(i,0,n)
    {
        if(s&(1<<i)) cout<<i+1<<" ";//如果 s 的第 i 位为 1 输出i
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int n;cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        print_subset(n,i);
    }
    return 0;
}
