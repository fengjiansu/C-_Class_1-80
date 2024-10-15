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
    stack<int> s; // 辅助栈
    int j=0;// 弹出序列的指针
    REP(i,0,n)
    {
        s.push(a[i]); // 将元素压入栈
        // 检查栈顶元素是否和弹出序列的当前元素相同
        while(!s.empty()&&s.top()==b[j])
        {
            s.pop();// 弹出栈顶元素
            j++;// 移动弹出序列指针
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
