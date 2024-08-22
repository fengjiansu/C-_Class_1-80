/* 

题目描述
给定一个字符串,在第k个字符后面放一面镜子,字符串
就会变成S1S2S3 ... Sk-1SkSkSk-1 .. S3S2S1这种形式。
问放完镜子后能看到的字典序最小的字符串。
a 的字典序比b小,满足:
· a是b的前缀且azb;
· 相同位置,a第一个与b不同的字符在字母表中先出现。

输入
一个正整数t,表示t组测试数据,不超过10000组。接下
来t组测试数据,每组数据第一行一个正整数n,接下来一
行长为n的字符串,n不超过100000。

输出
t行,每行一个符合题干要求的字符串。

(1804) Mirror in the String

输入样例
4
10
codeforces
9
cbacbacba
3

aaa
4
bbaa

输出样例
CC
cbaabc
aa
bb
 */


#include <bits/stdc++.h>

using namespace std;

void solve()
{
        int n;
        string s;
        cin >> n >> s;
        /* 
        codeforces
        cc 
        cbaabc
        当k+1个字符小于k个字符时继续后移
        
        aaa   aa
        bbaa  bb
        第2个于第一个字符相等时 在第一个字符后加镜子
        这个样例要自己想到
        cbbaaab
        cbbaabbc cbbaaaabbc
        当字符相等时且不在首位，继续后移直至语句下一个字符大于当前字符

        
         */
        int k = 0; // 初始k的位置
        for (int i = 1; i < n; ++i) {
            if(s[i]<s[i-1]|| (s[i]==s[i-1]&&i!=1))
            {
                k = i;
            }
            else{
                break;
            }
        }
        for(int i = 0; i <= k; ++i)
        {
            cout << s[i];
        }
        for(int i = k; i >=0; i--)
        {
            cout << s[i];
        }
        cout << endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    solve();
   }
   return 0;
}
