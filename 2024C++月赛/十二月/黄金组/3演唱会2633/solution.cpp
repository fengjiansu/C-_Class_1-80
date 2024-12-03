#include<bits/stdc++.h>
using namespace std;
struct song{
    int id,k;
}h[1005];
bool cmp(song a,song b){
    return a.k>b.k;
}
int n,m,a,b,x,ex,maxk;
int main(){
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++){//a名同学
        for(int j=1;j<=n;j++){//每人对n首歌的快乐值
            cin>>x;
            h[j].k+=x;
            h[j].id=j;
            if(i==b&&x>maxk){//记录她最喜欢的歌的编号
                maxk=x;
                ex=j;	
            }
        }
    }
    sort(h+1,h+n+1,cmp);//排序
    bool f=0;//判断ex是否在歌单里
    for(int i=1;i<=m;i++)
        if(h[i].id==ex) f=1;
    if(f){
        cout<<ex<<" ";//在歌单里，先输出ex
        for(int i=1;i<=m;i++){
            if(h[i].id!=ex) cout<<h[i].id<<" ";
        }
    }
    else{
        for(int i=1;i<m;i++) cout<<h[i].id<<" ";
        cout<<ex<<" ";
    }
    return 0;
}