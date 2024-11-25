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
1. ������ʱ��d����d��ͬ�İ���p����
2.����Ʒ�����ȼ����д洢
3.ÿ�δӶ���ȡ������ʱ���������Ʒ�͵�ǰ���ڱȽ�
4.�������ʱ��С�ڵ��ڵ�ǰ���ڣ���ô�����Ʒ���Թ���
�����:˼·���޷���̬������ѡ��Ʒ
��һ����������ǰ��Ҫ����
��ȷ˼·:
����һ�����͵� ̰���㷨 ���⣬������ ������� ���⣬����ÿ��������һ����ֹʱ���һ�����档
���ǵ�Ŀ���������޵�ʱ���ڣ�ÿ��ֻ����һ����Ʒ����ѡ��һ����Ʒ��ʹ�������������������Ʒ���ڹ�������֮ǰ������
������ʱ�����򣺽�������Ʒ���չ���ʱ�� ��С�����������ȴ������ʱ�������Ʒ��
1. ������ʱ������
��������Ʒ�������ǵĹ���ʱ�� ��С��������
���ȿ��ǹ���ʱ��������Ʒ��ȷ����Щ��Ʒ��������ڶ��޷����ۡ�

2.ʹ����С�ѣ����ȶ��У���ʹ��һ����С�ѣ�priority_queue������̬ά����ǰѡ�����Ʒ����
��С�ѵ������ǶѶ�Ԫ������С�ģ�����������������Ҫ��ʱ���Ƴ�������С����Ʒ
3.������Ʒ�б�
����ÿ����Ʒ �������� ������С�ѡ�
�����С�ѵĴ�С�����˵�ǰ��Ʒ�Ĺ���ʱ�� 
��Ӷ����Ƴ�������С����Ʒ����ȷ�����ڽ��� 
���ڣ�ֻѡ������������Ʒ��
��ʱ�䣨����������ʱ�������������ȱ���������ߵ���Ʒ
���������󣺱�����������Ʒ����С���е���������֮�ͼ�Ϊ��������档
�ѵĴ�С������Ʒ���� ,��Ʒ��d��ζ����d��������
 */
struct Node
{
    int p,d;
};
struct Cmp1
{
    bool operator()(Node a,Node b)
    {
        return a.d<b.d;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Node> v(n);
    priority_queue<int,vector<int>,greater<int>> q;
    REP(i,0,n)
    {
        cin>>v[i].p>>v[i].d;
    }
    sort(v.begin(),v.end(),Cmp1());
    for(auto &vi:v) //O(n)
    {
        q.push(vi.p);//(nlogn)
        if(q.size()>vi.d)
        {
            q.pop();
        }

    }
    int res=0;
    while(!q.empty())
    {
        res+=q.top();
        q.pop();
    }

    cout<<res<<endl;
    return 0;
}
