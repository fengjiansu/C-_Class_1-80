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
    vector<int> a={3,10,7,5,8};
    priority_queue<int> pq(a.begin(),a.end());
    for (auto temp = pq; !temp.empty(); temp.pop()) {
    cout << temp.top() << " ";
}
    return 0;
}
