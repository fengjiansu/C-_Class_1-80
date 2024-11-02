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
    int n;
    cin>>n;
    vector<string> v1(n);
    vector<string> res;
    int m=0;
    REP(i,0,n)
    {
        string str;
        cin>>str;
        m = max(m,(int)str.size());
        v1.push_back(str);
    }
    //cout<<m;
    reverse(v1.begin(),v1.end());
    //cout<<m;
    for(int i=0;i<m;i++)
    {
        string temp = "";
        //cout<<37<<endl;
        for(int j=0;j<n;j++)
        {
            if(i<v1[j].size())
            {
                temp += v1[j][i];
                //cout<<v1[j][i]<<endl;
            }
            else
            {
                temp += "*";
            }
            
        }
        //cout<<temp<<endl;
        while(temp.back()=='*')
        {
            temp.pop_back();
        }
        //cout<<temp<<endl;
        res.push_back(temp);
    }
    RFOR(x,res)
    {
        cout<<x<<endl;
    }
    return 0;
}
