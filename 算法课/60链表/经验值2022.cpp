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
int pos[MAXN];
bool vis[MAXN];
void insertAfter(int k, int x) {
    int R = nxt[k];   // k�����ھ�
    nxt[k] = x;
    pre[x] = k;
    nxt[x] = R;
    if (R != -1) {
        pre[R] = x;
    }
}
// ����IDɾ���ڵ�x
void removeByID(int x) {
    int L = pre[x], R = nxt[x];
    if (L != -1) nxt[L] = R;
    if (R != -1) pre[R] = L;
    // ��x���������Ƴ�
    pre[x] = -1;
    nxt[x] = -1;
    vis[x] = 1;
}

// �������ڵ㿪ʼ��ӡ��ǰ����
void printListFromLeft() {
    // �������ڵ�
    int start = 1;
    while (pre[start] != -1) {
        start = pre[start];
    }

    // ��start���ұ������
    for (int cur = start; cur != -1; cur = nxt[cur]) {
        cout << cur << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];    
        pos[val[i]] = i;
        pre[i]= i==1?-1:i-1;
        nxt[i] = i==n? -1:i+1;
    }  
    long long sum = 0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        int id = pos[x];
        if(nxt[id]!=-1 )
        {
            sum +=val[nxt[id]];
        }
        if(pre[id]!=-1)
        {
            sum+=val[pre[id]];
        }
        removeByID(id);
    }
    cout<<sum;                  
    return 0;
}
