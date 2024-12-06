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
�˳����� A �е�Ԫ����ӵ��� n
1+2 �� 2+1��һ���� ����Ҫ���⴦��
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
    int x = A.size()?A.back():1; // ��һ���ù��������ܽ�����
    for(int i=x;i<n;i++)
    {
        if(sum+i > n) continue; //����forѭ����дn
        
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
