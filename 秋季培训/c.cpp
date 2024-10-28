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
    vector<int> q(n),a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    REP(i,0,n)
    {
        cin>>a[i];
    }
    REP(i,0,n)
    {
        cin>>b[i];
    }
    int max_r = 0;
    bool find = false;
    REP(i,0,1000001)
    {
        bool f = true;
        int max_b = 1e6;
        REP(j,0,n)
        {
            if(a[j]*i >q[j])
            {
                f = false;
                break;
            }
            if(b[j]>0)
            {
                if(q[j] - a[j] * i < 0)
                {
                    f = false;  // 如果 q[j] - a[j] * i 为负，说明当前 i 不可能成立
                    break;
                }
                
                max_b = min(max_b,(q[j]-a[j]*i)/b[j]);
            }
            
        }
        if(f)
        {
            find= true;
            max_r = max(max_r,i+max_b);
        }

        
    }
    if(find)
    cout<<max_r<<endl;
    else cout<<0<<endl;

    return 0;
}
