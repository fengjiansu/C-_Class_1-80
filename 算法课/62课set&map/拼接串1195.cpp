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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    unordered_set<string> stringSet;
    vector<string> strings(n);
    for(int i=0;i<n;i++)
    {
        cin>>strings[i];
        stringSet.insert(string[i]);
    }
    vector<string> result;
    for(auto & s: strings)
    {
        int len = s.length();
        bool isConcat = false;

        for(int i=1; i<len;i++)
        {
            string left = s.substr(0,i);
            string right = s.substr(i);
            if(stringSet.count(left) && stringSet.count(right))
            {
                isConcat = true;
                break;
            }
        }
        if(isConcat)
        {
            result.push_back(s);
        }
    }
    for(auto &it :result)
    {
        cout<<s<<'\n';
    }
    return 0;
}
