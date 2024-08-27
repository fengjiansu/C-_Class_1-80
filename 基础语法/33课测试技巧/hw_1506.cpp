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
    int n,s;
    cin >> n >> s;
    vi a(n);
    REP(i,0,n)
    {
        cin >> a[i];
    }
    int maxl = 0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=i;j<n;j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++) sum += a[k];
            if(sum <= s) maxl = max(maxl,j-i+1);
        }
    }
    cout<<maxl;
    return 0;
}
