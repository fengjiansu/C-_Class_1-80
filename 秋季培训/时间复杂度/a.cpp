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
    vector<int> a(n);
    int res = 0;
    REP(i,0,n/5)
    {
        int x = n-i;
        REP(j,0,x/3)
        {
            if(i*5+j*3+(n-i-j)*3==n)
            {
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
