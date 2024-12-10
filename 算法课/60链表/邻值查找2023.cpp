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
const int MAXN = 1e5 + 10;
int pre[MAXN],nxt[MAXN],val[MAXN];
int b[MAXN],c[MAXN];

/* 
�����ŵĽڵ�Ϊ�ṹ������,
���� ֮��Ҫ�ҵ�iȡnʱ, jֻ��ȡ1��n-1,
��ֵ��ļ���ʱ jҪС��i
����˼�����鷳,��Ҫ�ж�j�Ƿ�����
����˼��,��iȡnʱ , �����ڽӵ�һ��С��n
��������������,�Ѹýڵ�ɾ��
��iΪn-1ʱ ,�ڽӵĽڵ�һ��С��n-1,
�������������ʱֻ��Ҫ�ж� �ýڵ�ǰ�������ڵ�Ĳ�ֵ����

 */
struct Node
{
    int id;
    int val;
};

bool cmp1(Node a, Node b)
{
    return a.val < b.val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<Node> a(n+1);
    for (int i = 1; i <=n; i++)
    {
        cin>>a[i].val;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), cmp1);
    // �������������� ��������,idΪ�����нڵ�ı��,valΪ�ڵ��ֵ
    for (int i = 1; i <= n; i++)
    {
        pre[a[i].id] = i==1?-1:a[i-1].id;
        nxt[a[i].id] = i==n? -1:a[i+1].id;
        val[a[i].id] = a[i].val;
    }
    // ����ֵ��ʱ i��n��ʼ��
    for(int i=n;i>=2;i--)
    {
        int L = pre[i], R = nxt[i]; 
		//cout<<"L: "<<L<<"R: "<<R<<endl;
        int lmin=1e9,rmin = 1e9; // ���ڼ�¼��С����ֵ��
        if (L != -1) lmin = min(lmin, abs(val[i] - val[L])); // �������ھӵ���ֵ��
        if(R!=-1) rmin = min(rmin, abs(val[i] - val[R])); // �������ھӵ���ֵ��
        //cout<<"lmin: "<<lmin<<"rmin: "<<rmin<<endl;
        if(lmin<=rmin) // ���ڵ����,����valС�Ľڵ� ����ߵĽڵ�
        {
            b[i] = lmin;
            c[i] = L;
        }
        else
        {
            b[i] = rmin;
            c[i] = R;
        }
        // ɾ���ڵ�i
    if (L != -1) nxt[L] = R;
    if (R != -1) pre[R] = L;
    // ��i���������Ƴ�
    pre[i] = -1;
    nxt[i] = -1;

    }
    for(int i=2;i<=n;i++) cout<<b[i]<<" "<<c[i]<<endl;
    return 0;
}
