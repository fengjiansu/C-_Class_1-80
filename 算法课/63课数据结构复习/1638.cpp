/* 
(1638)ɾ������

����n����������,Ȼ��������һ��1~n������,����������е�˳��ɾ��ԭ�����е�ÿһ
�����֡�ÿ��ɾ���ֵ�ʱ��,����Ҫ����������ֵ��������ߵ����ֵĴ���(ע�����ĳ��
���ֱ�ɾ����,����ߺ����ұߵ����־�������,���ĳһ��û�����־Ͳ���),������
���ۺ�Ϊ����?
����
������n,������n���Ǹ�����a,����������һ������,n��10^6,a��1000��
���
������Ĵ��ۺ͡�
��������
4
7413
2314

��Ŀ����

�������
21
 */
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

struct Node
{
    int pre;
    int value;
    int next;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<Node> node(n+2); //Ԥ��λ��
    vector<int> p(n+1);
    vector<int> a(n+1);
    for(int i = 1; i < n+1; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i < n+1; i++)
    {
        cin>>p[i];
    }
    for(int i = 1; i < n+1; i++)
    {
        node[i].value = a[i];
        node[i].pre = i - 1;
        node[i].next = i + 1;
    }
    ll cost = 0;
    for(int i = 1; i < n+1; i++)
    {
        int pos = p[i];
        if(node[pos].pre >=1)
        {
            cost += node[node[pos].pre].value;
        }
        if(node[pos].next <= n)
        {
            cost += node[node[pos].next].value;
        }
        if(node[pos].pre >=1)
        {
            node[node[pos].pre].next = node[pos].next;
        }
        if(node[pos].next <= n)
        {
            node[node[pos].next].pre = node[pos].pre;
        }
        // ��ǽڵ���ɾ������ѡ��
        node[pos].pre = node[pos].next = 0;
    } 
    cout<<cost;  
    return 0;
}
