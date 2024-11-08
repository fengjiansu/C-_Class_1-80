#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,c=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        c*=m;
    }
    if(c>1000000)cout<<">1000000";
    else cout<<c;
    return 0;
} 