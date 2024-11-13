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

void print_permutation(vector<int> &A, int n)
{
    if (A.size() == n)
    {
        RFOR(it, A)
        cout << it;
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            /* if(find(A.begin(),A.end(),i)==A.end())
            {
                A.PB(i);
                print_permutation(A,n);
                A.pop_back();
            } */
            
                A.PB(i);
                print_permutation(A, n);
                A.pop_back(); // 可以先不写这段代码,展示一下,然后再问递归的时候返回到上一层比如找到123了之后是不是要回到12,之后再回到1
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> A;
    print_permutation(A, 10);
    /* REP(a,1,4)
    {
        REP(b,1,4)
        {
            REP(c,1,4)
            {
                REP(d,1,4)
                {
                    REP(e,1,4)
                    {
                        REP(f,1,4)
                        {
                            REP(g,1,4)
                            {
                                REP(h,1,4)
                                {
                                    REP(i,1,4)
                                    {
                                        REP(j,1,4)
                                        {
                                            cout<<a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } */
    return 0;
}
