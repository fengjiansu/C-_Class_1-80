#include<bits/stdc++.h>
using namespace std;
    cout<<fun
int dp[105];
int f(int n)
{
    if(dp[n]!=0) return dp[n];
    if(n==1|| n == 2)return dp[n]=1; //保证 dp 数组中记录了结果，便于后续查询
    return dp[n]=f(n-1)+f(n-2); // 赋值表达式 x = y 的返回值是 x，所以可以在赋值的同时直接返回值。

}
int main()
{
    int n;cin>>n;   
    cout<<f(n);

    return 0;
}