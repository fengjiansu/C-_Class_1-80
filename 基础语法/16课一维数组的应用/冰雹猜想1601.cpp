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
int a[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int i = 0;
    while(n!=1)
    {
        a[i] = n; //讲清楚怎么用数组保存
        i++;
        if(n%2==0)
        {
            n = n/2;
        }
        else
        {
            n = 3*n+1;
        }
    }
    a[i] = 1;
    for(int j = i; j >= 0; j--)
    {
        cout << a[j] << " ";
    }
    return 0;
}
