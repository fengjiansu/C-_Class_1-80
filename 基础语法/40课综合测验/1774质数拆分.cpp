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
bool isPrime(int n)
{
    if(n==0||n==1) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //输入一个字符串仅包含字母和数字，将字符串中的质数拆分出来。
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    bool flag = 1;
    for (int i = 0; i < n; i++) 
    {
        if(isdigit(s[i]))
        {
            sum *= 10;
            sum += s[i] - '0';
        }
        else
        {
            if(isPrime(sum))
            {
                cout << sum << " ";
                flag = 0;
            }
            sum = 0;
        }
    }
    if(flag) cout<<"no"<<endl;
    return 0;
}
