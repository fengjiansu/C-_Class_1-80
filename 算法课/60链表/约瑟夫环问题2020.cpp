#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
const int MAXN = 1e5 + 10; // ����ʵ������������ڵ���, m , bn
string val[MAXN];
    int nxt[MAXN];
/*

�ڵ�ѭ�������У����һ���ڵ�� nxt ������ -1������ָ��ͷ�ڵ� head��
�����ɾ���ڵ�ʱ����Ҫ���⴦�����һ���ڵ�� nxt ָ�룬ȷ�������γ�һ������
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

     int n,m;
    cin>>n>>m;//����n��m
    for(int i=1;i<=n;i++)//����n���˵�����   
    {
    	cin>>val[i];
    }
    for(int i=0;i<n;i++)//��ʼ��
    	nxt[i]=i+1;
	nxt[n]=1;
	int p=0;//��0��ʼ  ��Ϊ���k==1�Ļ� p�����1��ʼ  ��ѵ�һ���ڵ�����,���Ե�һ���ڵ�֮ǰ����һ����λ
	for(int i=1;i<=n;i++){//��ʼģ���Ȧ����
		for(int j=0;j<m-1;j++)
			p=nxt[p];//pλ������
		cout<<val[nxt[p]]<<" ";//�����Ȧ�˵�λ��
		nxt[p]=nxt[nxt[p]];//ɾ����Ȧ��
	}
	return 0;//����Բ��

}
