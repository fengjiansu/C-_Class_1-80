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
��n��������ѡ��k������,�����Ӽ�����,ÿ������ֻ��ѡ1��
�������� �Ӽ��ǰ�ÿ�����ֶ�ѡ���߶���ѡ
���������ֻѡ��k�����ֶ��ұ���ѡ��k�� 

 */
bool isPrime(int n)
{
    if(n<2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int cnt =0;
void dfs(vi &A,vi & S,int n,int k,int start) //�������취
{
    if(A.size()==k)
    {
        int sum =0;
        for(int i=0;i<A.size();i++)
        {
            sum += A[i];
        }
        if(isPrime(sum))
        {
            /* for(int i=0;i<A.size();i++)
            {
                cout<<A[i]<<" ";
            }
            cout<<endl; */
            cnt++;
        }
        return;
    }
    //���A��Ϊ�գ���ô��A�����һ��Ԫ�ص���һ����ʼ
    // ��ʱ S ��Ԫ�ز���������,���Ա�������һ���������� 
    for(int i=start;i<n;i++)
    {
        A.push_back(S[i]);
        dfs(A,S,n,k,i+1); //ÿ����һ��ѡ���Ԫ������һ��λ��+1
        A.pop_back();
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;cin>>n>>k;
    vi A,S(n);
    for(int i=0;i<n;i++) cin>>S[i];
    dfs(A,S,n,k,0);
    cout<<cnt<<endl;
    return 0;
}
