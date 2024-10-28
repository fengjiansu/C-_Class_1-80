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
    int N, K, B;
    cin >> N >> K >> B;

    
    vi broken(N + 1, 0); 

    for (int i = 0; i < B; ++i) {
        int x;
        cin >> x;
        broken[x] = 1;  
    }

    int cnt = 0;
    for (int i = 1; i <= K; ++i) {
        cnt += broken[i];
    }

    int min_broken = cnt;
    for (int i = K + 1; i <= N; ++i) {
        cnt += broken[i];      
        cnt -= broken[i - K]; 
        min_broken = min(min_broken, cnt); 
    }

    cout << min_broken << endl;

    return 0;
}
