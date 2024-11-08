#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n];
    long long maxx= LONG_LONG_MIN;
    long long minn=LONG_LONG_MAX;//¸ü¸Ä
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>maxx) maxx=a[i]; 
    }
    for(int i=0;i<n;i++){
        if(a[i]<minn) minn=a[i]; 
    }
    for(int i=0;i<n;i++){
        cout<<maxx-a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]-minn<<" ";
    }
    return 0;
}