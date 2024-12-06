#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
/* 
退出条件 A 中的元素相加等于 n
1+2 和 2+1是一样的 所以要特殊处理
 */
void dfs(vector<int> &A,int n)
{
    int sum =0;
    for(auto &it : A)
    {
        sum += it;
    }
    if(sum == n)
    {
        for(int i=0;i<A.size();i++)
        {
            if(i>0) cout<<'+';
            cout<<A[i];
        }
        cout<<"\n";
        return;
    }
    int x = A.size()?A.back():1; // 上一个用过的数还能接着用
    for(int i=x;i<n;i++)
    {
        if(sum+i > n) continue; //或者for循环里写n
        
        A.push_back(i);
        dfs(A,n);
        A.pop_back();
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vector<int> A;
    dfs(A,n);
    return 0;
}
