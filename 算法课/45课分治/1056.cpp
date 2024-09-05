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

int sumN(int l,int r)
{
    if(l==r)
    {
        return l;
    }
    int mid = l+(r-l)/2;
    int sumLeft = sumN(l,mid);
    int sumRight = sumN(mid+1,r);
    return sumLeft+sumRight;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout<<sumN(1,n);
    return 0;
}
