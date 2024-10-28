#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

const double EPS = 1e-6;
/* 
������ EPS ���ã�
1e-2�����ڽϵ;���Ҫ������⣬��ֻ�豣��һλС����
1e-3�����ڱ�����λС���������
1e-6�����ڴ󲿷ֳ������⣬��ͨ������Ϊ��Ĭ�ϵġ��㹻���ȡ���
1e-9 ���С����ĳЩ�߾��ȼ��㳡���£�������Ҫ���ü�С�� EPS���Ա�֤���ߵľ��ȡ�
 */
bool check(double mid,vector<double> &v,vi &s)
{
    double sum = 0;
    int n = v.size();
    REP(i,0,n)
    {
        double vt = v[i]+mid;
        if(vt<=0) return false;
        sum += s[i]/vt;
    }
    return sum<=0.5;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<double> v(4);
    vector<int> s(4);
    REP(i,0,4)
    {
        cin>>v[i];
    }
    REP(i,0,4)
    {
        cin>>s[i];
    }

    double ans=0;
    double r = 50,l = 0;
    while(r-l>EPS)//������Ҫͨ�����������С���ƽ��⣬��������������������ȷ�ķֽ��
    {
        double mid = l+(r-l)/2.0;
        double sum = 0;
        if(check(mid,v,s))
        {
            ans = mid;
            r = mid; //����������ʱ����ֱ�Ӽ�1,������֮��ľ����ǿ��Էǳ�С�ġ�����ֻ��Ҫ�������㹻Сʱֹͣ���ң���˲���Ҫ������ɢ�Ĳ�����Ծ���¡�
        }
        else
        {
            l = mid;
        }

    }
    cout<<setprecision(2)<<fixed<<ans<<endl;
    return 0;
}
