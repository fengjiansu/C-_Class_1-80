#include<bits/stdc++.h>
using namespace std;

bool isOpen[105];
int main()
{
	
	for(int i=1;i<=100;i++)//用i表示服务员
	{
		for(int j=i;j<=100;j++)//用j表示房间
		{
			if(j%i==0)//房间是服务台编号的倍数
			{
				isOpen[j] = !isOpen[j];
			}	
		} 
	}
	for(int i=1;i<=100;i++)
	{
		if(isOpen[i])
		{
			cout<<i<<" ";
		}
	}
	return 0;
}