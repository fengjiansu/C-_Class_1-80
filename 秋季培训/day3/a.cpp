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

int main() {
    ll N;
    cin >> N; 
    string str;
    cin >> str;
    int n1=0;
    REP(i,0,N)
    {
        if(str[i]=='1')
        {
            n1++;
        }
    }
    if(N>=2)
    {
        if(str[0]=='1'&&str[1]=='0')
        {
            cout<<n1;
            return 0;
        }
        if(str[N-2]=='0'&&str[N-1]=='1')
        {
            cout << n1 << endl;
            return 0;
        }
    } 
    
    

    // 输出最少的初始感染人数
    cout <<res << endl;

    return 0;
}
