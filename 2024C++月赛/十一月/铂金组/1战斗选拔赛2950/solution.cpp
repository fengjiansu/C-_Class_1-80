#include <bits/stdc++.h>
using namespace std;
struct p {//�ṹ��
	int id;
    int jun;
}s[101];
bool cmp(p a,p b) {//��ÿ������ָ���ܺͽ����Զ�������
	return a.jun>b.jun;
}
int main() {
	int n,k;
	cin>>n>>k;
	for(int j=1; j<=n; j++) {
		int sum=0;
		for(int i=1; i<=k; i++) {
			int z;
			cin>>z;
			sum+=z;//����ÿ������ָ���ܺ�
		}
		s[j].jun=sum;
		s[j].id=j;
	}

	stable_sort(s+1,s+n+1,cmp);//����
   cout<<s[1].id<<endl<<s[2].id;
	return 0;
}