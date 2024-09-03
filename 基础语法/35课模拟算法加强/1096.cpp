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
    vi a(15);
    REP(i,1,13)
    {
        cin>>a[i];
    }
    int sum = 0;
    int c = 0; // ´æÆðÀ´µÄÇ®
    REP(i,1,13)
    {
        sum+= 300;
        if(sum<a[i])
        {
            cout<<"-"<<i; 
            return 0;
        }
        sum -= a[i];
        if(sum/100>0)
        {
            
            c += sum/100 *100;
            sum -= sum/100 *100;
        }
    }
    cout<<sum+c*1.2;
    return 0;
}
