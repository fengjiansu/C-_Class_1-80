#include<bits/stdc++.h>
using namespace std;
    cout<<fun
int dp[105];
int f(int n)
{
    if(dp[n]!=0) return dp[n];
    if(n==1|| n == 2)return dp[n]=1; //��֤ dp �����м�¼�˽�������ں�����ѯ
    return dp[n]=f(n-1)+f(n-2); // ��ֵ���ʽ x = y �ķ���ֵ�� x�����Կ����ڸ�ֵ��ͬʱֱ�ӷ���ֵ��

}
int main()
{
    int n;cin>>n;   
    cout<<f(n);

    return 0;
}