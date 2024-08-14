#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,sum=0;
    cin>>m>>n;
    int jiu,ping,gai;
    //先买酒瓶
    jiu = n/m;
    ping = jiu;
    gai = jiu;
    sum += jiu;
    //卖完之后再开始换酒瓶
    while(jiu)
    {
        jiu = ping/2+gai/4;
        //瓶子的数量 加上上一步剩下的    
        ping = jiu+ping%2;
        gai = jiu +gai%4;
        sum+= jiu;
    }
    cout<<sum;
    
    return 0;
}