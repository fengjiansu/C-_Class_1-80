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
int a[105];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n>>k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    k--;//因为数组下标从0开始,题目的k是第k个元素
    //从第k个元素开始输出 整个数组
    for(int i = k; i < n; i++)
    {
        cout << a[i] << " ";
    }
    //输出前k个元素
    for(int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
