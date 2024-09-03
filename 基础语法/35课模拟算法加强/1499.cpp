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
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int ans=1;
    while(a>0&&b>0){
        if(ans%2)
        {
            a-=3;
        }
        else
        {
            b-=5;
        }
        ans++;
    }    
    cout<<ans-1;
    return 0;
}
