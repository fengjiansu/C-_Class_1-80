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

int a[55];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num;
    cin>>num;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //������� �ҵ���һ������num��λ��
    int j = 0;
    while(j < n && a[j] <= num)
    {
        j++;
    }
    //�ҵ�λ��֮�� �����һ��Ԫ�ؿ�ʼ�����ƶ�
    for(int i = n-1; i >= j; i--)
    {
        a[i+1] = a[i];
    }
    //�ƶ��� ����
    a[j] = num;
    for(int i = 0; i < n+1; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
