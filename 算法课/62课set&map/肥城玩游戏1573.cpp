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
    int n,m;
    cin >> n;
    REP(i,0,n)
    {
        cin>>a[i];
    }
    //unordered_set无序集合 
    //基于哈希表 
    //插入、删除、查找操作的平均时间复杂度为 O(1)

    unordered_set<int> sum_set;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum_set.insert(a[i]+a[j]);
        }
    }

    //遍历所有两数之和
    bool found = false;
    for(auto &it: sum_set)
    {
        if(sum_set.count(m-s1))
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }
    return 0;
}
 