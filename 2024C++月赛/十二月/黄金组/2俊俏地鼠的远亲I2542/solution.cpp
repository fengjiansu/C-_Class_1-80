#include<bits/stdc++.h>
using namespace std;
int b[55][55],n,m,x,y;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>b[i][j];	
	}
	cin>>x>>y;
	int maxs=0,s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==b[x][y]){
				s=(x-i)*(x-i)+(y-j)*(y-j);
				if(s>maxs) maxs=s;
			}
		}
	}
	cout<<maxs;
    return 0;
}