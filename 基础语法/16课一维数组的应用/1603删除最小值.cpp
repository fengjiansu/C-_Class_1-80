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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // �ҵ���Сֵ��λ��
    int j = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[j])
        {
            j = i;
        }
    }
    
    /* //�ڶ���˼·,���ñ������
    bool mark[105] = {0};
    //ɾ����λ�ñ��Ϊ1,��ʾ��ɾ��
    mark[j] = true;
    for(int i = 0; i < n; i++)
    {
        if(mark[i] == 0)
        {
        cout<<a[i]<<" ";
        }
    } */
    
    // ��jλ�ÿ�ʼ ��ǰ�ƶ�
    for(int i = j; i < n-1; i++)
    {
        a[i] = a[i+1];
    }
    // �ƶ�������һ��Ԫ������
    a[n-1] = 0;
    for(int i = 0; i < n-1; i++)
    {
        cout << a[i] << " ";    
    }

    return 0;
}
