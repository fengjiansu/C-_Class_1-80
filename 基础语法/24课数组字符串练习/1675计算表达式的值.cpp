#include <bits/stdc++.h>

using namespace std;

string s;
int main()
{
    cin >> s;
    long long a = 0;
    // int x;
    // �����۳���
    long long ji = 1;
    for (int i = 0; i < s.size(); i++)
    {

            if (s[i] != '*')
            {        //cout<<"a*10 "<<a*10<<"s[i]-'0' "<<s[i]-'0'<<endl;
                    a = a * 10 + s[i] - '0'; // 1 ��ô��11
                    //cout<<" a: "<<a;
            }
            else
            {
                ji *= a;
                //cout<<" ji: "<<ji<<endl;
                a = 0; // ���a
                /* for(int j=0;j<a.size();j++)
                {
                    ji*=a[j]-'0';
                }
                */
            }
    }
    ji *= a;
    cout << ji;
    return 0;
}