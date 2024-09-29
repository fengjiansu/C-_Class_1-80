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

int a[55];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num;
    cin>>num;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //升序插入 找到第一个大于num的位置
    int j = 0;
    while(j < n && a[j] <= num)
    {
        j++;
    }
    //找到位置之后 从最后一个元素开始往后移动
    for(int i = n-1; i >= j; i--)
    {
        a[i+1] = a[i];
    }
    //移动完 插入
    a[j] = num;
    for(int i = 0; i < n+1; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
