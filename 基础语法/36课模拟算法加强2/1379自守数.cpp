/* 
C. 自守数
描述

如果某个数k的平方乘以n以后,结果的末尾几位数等于k,那么就称这个数为“n-自守
数”。例如3×922=25392,而25392的末尾两位正好是92,所以92是一个3-自
守数。
本题就请你编写程序判断一个给定的数字是否关于某个n是n-自守数。

输入

输入一个正整数k

输出

如果它是n-自守数就在一行中输出最小的n和nk2的值,否则输出nO

 */
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
int wei(int k)
{
    int w = 0;
    while(k)
    {
        k/=10;
        w++;
    }
    return w;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    ll res;
    int w = wei(k);
    REP(i,1,11)
    {
        res = pow(k,2)*i;// pow的返回值是double
        //计算k的长度 to_string(k).length()
        // to_stirng(k); c++11 就像手机软件会更新版本，C++ 也会不断地更新，让程序设计变得更简单、更强大。把整数和浮点数转换为字符串 浮点数转换可能不准确
        if(res%(ll(pow(10,w))) == k)
        {
            cout<<i<<" "<<res;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}
