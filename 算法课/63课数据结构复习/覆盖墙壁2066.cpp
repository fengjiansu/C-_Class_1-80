#include<iostream>
using namespace std;

const int maxn=1e6+5;
const int mod=10000;

int f[maxn],g[maxn];

int main()
{
	int n;
	
	cin>>n;
	
	f[1]=1;
    f[2] = 2;
	g[2]=1;
	for(int i=3;i<=n;i++)
	{
		f[i]=((f[i-1]+f[i-2])+2*g[i-1])%mod;
		g[i]=(g[i-1]+f[i-2])%mod;
	}
	cout<<f[n]<<endl;
	
	return 0;
}