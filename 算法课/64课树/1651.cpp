
/* ��«�ޣ���«�ޣ�һ�����Ϻö�仨�����ں�«���Ѿ��ҵ���үү���ֵ�үү��ʼ�Һ�«���������벻���ɣ���Ҳ�벻�� 

������һ��n���ڵ����,�ڵ���Ϊ1?n,���ڵ�Ϊ1�Žڵ㡣���������뷽ʽ������һ����
��һ������n,
��ʾ���Ľڵ����,�ڶ����ÿո�ָ�����n?1�����������ֱ��ʾ2?n�Žڵ�ĸ��ڵ�ı�š� 
�������ٵ�3������һ������q��ʾ��������q��ѯ�ʣ�ÿ��ѯ������һ��1?n����֮�����������Ҫ���������ڵ���ӽڵ������Ȼ���ձ�Ŵ�С�����������ڵ���ӽڵ㡣
n,q��1000 */

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
    int n;
    cin>>n;
    vector<set<int>> tree(n+1);
    int p;
    REP(i,2,n+1)
    {
        cin>>p;
        tree[p].insert(i);//i�ĸ��ڵ���p
    }
    int q;
    cin>>q;
    int a;
    while(q--)
    {
        cin>>a;
        cout<<tree[a].size()<<"\n";
        //set<int>::iterator it;
    /*     for(auto i=tree[a].begin();i!=tree[a].end();i++)
        {
            cout<<*i<<" ";
        } */ 
         
        for (auto &it : tree[a])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

 int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    int p;
    REP(i,2,n+1)
    {
        cin>>p;
        tree[p].push_back(i);//i�ĸ��ڵ���p
    }
    int q;
    cin>>q;
    int a;
    while(q--)
    {
        cin>>a;
        cout<<tree[a].size()<<"\n";
        sort(tree[a].begin(),tree[a].end());
        for(int i=0;i<tree[a].size();i++)
        {
            cout<<tree[a][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
