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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
/* 
���������ʾ�Ӽ���ʹ��ÿһλ��Ӧ��Ԫ�ر�źͶ���������Ȩֵ˳��һ��

 */

void print_subset(int n, int s)//��s����Ķ����������Ӽ����
{
    REP(i,0,n)
    {
        if(s&(1<<i)) cout<<i+1<<" ";//��� s �ĵ� i λΪ 1 ���i
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int n;cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        print_subset(n,i);
    }
    return 0;
}
