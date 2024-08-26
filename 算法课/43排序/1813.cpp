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
    //开桶时遇到负数可以偏移
    int n;
    cin>>n;
    vi a(105);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x+50]++;
    }
    for(int i=0;i<100;i++)
    {
        // 不能是等于
        if(a[i]>n/2)
        {
            cout<<i-50<<endl;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}
