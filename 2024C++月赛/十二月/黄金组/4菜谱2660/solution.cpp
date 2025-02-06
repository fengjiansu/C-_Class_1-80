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
    int max_r = INT_MIN;
    REP(i,0,1001)
    {
        bool f = true;
        int max_b = 1000;
        REP(j,0,n)
        {
            if(a[j]*i >q[j])
            {
                f = false;
                break;
            }
            if(b[j]>0)
            {
                max_b = min(max_b,(q[j]-a[j]*i)/b[j]);
            }
            
        }
        if(f)
        {
            max_r = max(max_r,i+max_b);
        }

        
    }

    cout<<max_r<<endl;

    