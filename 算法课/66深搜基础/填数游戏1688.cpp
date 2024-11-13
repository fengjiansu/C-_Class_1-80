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
ll cnt;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
void print_permutation(vector<int> &A,int &x)
{
    if (A.size() == 3)
    {
        
            ll res = A[0]*100000+A[1]*10000+A[2]*1000+x;
            if(isPrime(res)){
                cout<<res<<endl;
                cnt++;
            } 

        return;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            /* if(find(A.begin(),A.end(),i)==A.end())
            {
                A.PB(i);
                print_permutation(A,n);
                A.pop_back();
            } */
            if(A.size()==0 && i==0) continue;
                A.PB(i);
                print_permutation(A, x);
                A.pop_back(); // 可以先不写这段代码,展示一下,然后再问递归的时候返回到上一层比如找到123了之后是不是要回到12,之后再回到1
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>x;
    vi v;
    print_permutation(v,x);
    cout<<cnt<<endl;
    return 0;
}
