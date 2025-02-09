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

struct node
{
    int a,b;
    bool operator < (const node &x) const
    {
        return a<x.a;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> v(n);
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        
        cin >> a >> b;
        v[i].a = a-b;
        v[i].b = a+b;

    }
    sort(v.begin(),v.end());
    int ans = 0;    // �������ˮ����
    int cur = 0;    // ��ǰ�Ѹ��ǵ��Ҷ�λ��
    int i = 0;
    while(cur < 10000){
        int best = cur;
        // �ҳ�������˵㲻������ǰ����λ�õ����䣬ѡ�������Ҷ˵���Զ��
        while(i < n && v[i].a <= cur){
            best = max(best, v[i].b);
            i++;
        }
        // ����޷��ҵ��µ����䣬��˵���޷��������ǣ���Ŀ��֤���ݶ��н⣬���ﲻ�ش���
        if(best == cur){
            break;
        }
        ans++;
        cur = best;
    }
    
    cout << ans << "\n";
    return 0;
}
