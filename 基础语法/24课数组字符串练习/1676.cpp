#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i] = s[i]-'a'+'A';
        }
    }
    //cout<<s<<endl;
    char c = s[0];
    int cnt = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i]!=c)
        {
            cout<<'('<<c<<','<<cnt<<')';
            cnt = 1;
            c = s[i];
        }
        else{
            cnt++;
        }
    }
    //×¢Òâ×îºó
    cout<<'('<<c<<','<<cnt<<')';
    return 0;
}
