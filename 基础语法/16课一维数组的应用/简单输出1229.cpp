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
int a[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n>>k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    k--;//��Ϊ�����±��0��ʼ,��Ŀ��k�ǵ�k��Ԫ��
    //�ӵ�k��Ԫ�ؿ�ʼ��� ��������
    for(int i = k; i < n; i++)
    {
        cout << a[i] << " ";
    }
    //���ǰk��Ԫ��
    for(int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
