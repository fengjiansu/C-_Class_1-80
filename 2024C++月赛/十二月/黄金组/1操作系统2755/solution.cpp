#include<bits/stdc++.h> 
using namespace std;
string s,ans;
int fr,fn;
int main(){
    getline(cin,s);
    for(int i=0;i<s.size()-1;i++){
        if(s.substr(i,2)=="\\r") fr=1;
        else if(s.substr(i,2)=="\\n") fn=1;
    }
    if(fr&&fn) cout<<"windows";
    else if(fr) cout<<"mac";
    else cout<<"linux";
    return 0;
}