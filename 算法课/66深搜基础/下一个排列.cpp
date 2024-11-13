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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1,3,2};
    //sort(v.begin(), v.end());
    do{
        RFOR(it,v) cout<<it<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}
