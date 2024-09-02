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

int main()
{
    ios::sync_with_stdio(0);//作用
    cin.tie(0);//作用是关闭cin和cout的缓冲区，提高运行速度
    int x, y;
    cin>>x>>y;
    vector<vector<int>> a(50,vector<int>(50,0));
    x+= 1;
    y+= 1;
    a[0+1][0+1] = 1;
    REP(i,1,x)
    {
        REP(j,1,y)
        {
            if(i==1 && j==1)
            {
                continue;
            }

            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    cout<<a[x-1][y-1]<<endl;
    return 0;
}
