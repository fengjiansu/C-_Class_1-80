#include<bits/stdc++.h>
using namespace std;

bool isOpen[105];
int main()
{
	
	for(int i=1;i<=100;i++)//��i��ʾ����Ա
	{
		for(int j=i;j<=100;j++)//��j��ʾ����
		{
			if(j%i==0)//�����Ƿ���̨��ŵı���
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