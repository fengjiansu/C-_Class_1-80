#include<bits/stdc++.h>
using namespace std;

string s,s0;
bool check(string x){
	int len=x.size();
	if(len<6||len>12) return 0;
	bool hasC=0, hasL=0, hasD=0, hasS=0;
	for(int i=0;i<len;i++) {
		if('A'<=x[i]&&x[i]<='Z') hasC =1;
		else if('a'<=x[i]&&x[i]<='z') hasL=1;
		else if('0'<=x[i]&&x[i]<='9') hasD=1;
		else if(x[i]=='!'||x[i]=='@'||x[i]=='#'||x[i]=='$') hasS=1;
		else return 0;
	}
	if(!hasS) return 0;//至少有四个特殊字符中的一个
	if(hasC+hasL+hasD<2) return 0;//大写字母、小写字母和数字必须至少有其中两种
	return 1;
}
int main() {
	cin>>s;
	// 按逗号对输入进行切分，并依次判断
	for(int i=0;i<s.size();i++){
		if(s[i]!=',') s0+=s[i];
		else{
			if(check(s0)) cout<<s0<<endl;
			s0="";
		}
	}
	if(check(s0)) cout<<s0<<endl;
	return 0;
}