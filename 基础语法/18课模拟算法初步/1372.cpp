#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,sum=0;
    cin>>m>>n;
    int jiu,ping,gai;
    //�����ƿ
    jiu = n/m;
    ping = jiu;
    gai = jiu;
    sum += jiu;
    //����֮���ٿ�ʼ����ƿ
    while(jiu)
    {
        jiu = ping/2+gai/4;
        //ƿ�ӵ����� ������һ��ʣ�µ�    
        ping = jiu+ping%2;
        gai = jiu +gai%4;
        sum+= jiu;
    }
    cout<<sum;
    
    return 0;
}