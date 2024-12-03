#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
long long a[100005];
set<long long> A;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]%k||A.find(a[i]/k)==A.end()){//如果不能整除k或者集合中没有a[i]/k，满足条件就进入集合
            A.insert(a[i]);
        }
    }
    printf("%d\n",A.size());
    return 0;
}