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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0);
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) cin>>b[i];
    stack<int> s; // ����ջ
    int j=0;// �������е�ָ��
    REP(i,0,n)
    {
        s.push(a[i]); // ��Ԫ��ѹ��ջ
        // ���ջ��Ԫ���Ƿ�͵������еĵ�ǰԪ����ͬ
        while(!s.empty()&&s.top()==b[j])
        {
            s.pop();// ����ջ��Ԫ��
            j++;// �ƶ���������ָ��
        }
    }
    if(s.empty())
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
