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
    int n,m;
    cin >> n >> m;
    int sum = 0;
    REP(i,1,n+1)
    {
        REP(j,i+1,n+1)
        {
            if(i+j>m) sum++;
        }
    }
    cout<<sum;
    return 0;
}
