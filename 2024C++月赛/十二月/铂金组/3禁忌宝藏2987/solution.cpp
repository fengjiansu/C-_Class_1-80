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
        if(a[i]%k||A.find(a[i]/k)==A.end()){//�����������k���߼�����û��a[i]/k�����������ͽ��뼯��
            A.insert(a[i]);
        }
    }
    printf("%d\n",A.size());
    return 0;
}