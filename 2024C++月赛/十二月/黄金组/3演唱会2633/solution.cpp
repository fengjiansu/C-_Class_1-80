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
    for(int i=1;i<=a;i++){//a��ͬѧ
        for(int j=1;j<=n;j++){//ÿ�˶�n�׸�Ŀ���ֵ
            cin>>x;
            h[j].k+=x;
            h[j].id=j;
            if(i==b&&x>maxk){//��¼����ϲ���ĸ�ı��
                maxk=x;
                ex=j;	
            }
        }
    }
    sort(h+1,h+n+1,cmp);//����
    bool f=0;//�ж�ex�Ƿ��ڸ赥��
    for(int i=1;i<=m;i++)
        if(h[i].id==ex) f=1;
    if(f){
        cout<<ex<<" ";//�ڸ赥������ex
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