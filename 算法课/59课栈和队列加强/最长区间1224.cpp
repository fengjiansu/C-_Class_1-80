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
��������ͨ���Ǵ� �����ұ��� ���㷨
���� left �� right �ֱ�Ϊ�������ڵ����ұ߽硣
����������һ�� ��չ-���� �Ĺ��̣�
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vi a(n);REP(i,0,n)cin>>a[i];
    int l =0;
    int sum = 0,maxl = 0;
    for(int r=0;r<n;r++)
    {
        sum += a[r];//��չ����
        //��������
        while(sum>m)
        {
            sum -= a[l];
            l++;
        }
        maxl = max(maxl,r-l+1);
    }
    cout<<maxl;
    return 0;
}
