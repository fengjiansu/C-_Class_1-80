#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,t;
cin>>a>>b>>c;
if(a>b){
t=a;
a=b;
b=t;
}
if(a>c){
t=a;
a=c;
c=t;
}
if(b>c){
t=b;
b=c;
c=t;
}
if(a+b<=c){
cout<<"illegal triangle"<<endl;
}
else if(a*a+b*b>c*c){
cout<<"acute triangle"<<endl;
}
else if(a*a+b*b==c*c){
cout<<"right triangle"<<endl;
}
else{
cout<<"obtuse triangle"<<endl;
}
return 0;
}