/* 
题目描述

(1109)子序列

输入两个字符串s和t,问是否能从t中删除0个或者多个字符(其他字符顺序不变),得到字符
串s。例如,abcde可以得到bce,但无法得到dc。字符串长度不超过10°。
输入
每行两个分别为s和t。多组输入。
输出
根据题意输出“Yes"或者“No",每组数据占一行。
输入样例
sequence subsequence
person compression
VERDI viva VittorioEmanueleReDiltalia
caseDoesMatter CaseDoesMatter

输出样例
Yes
No
Yes
No

 */
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

// 在t中找出s,通过删除字符的方式
bool isSubsequence(const string& s, const string& t) {
    int j = 0;  // 指向 s 的指针
    int i = 0;  // 指向 t 的指针
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;  // 如果匹配，i 往后移，匹配 s 的下一个字符
        }
        j++;  // 无论是否匹配，t 的指针都往后移
    }
    return i == s.length();  // 如果 i 遍历完 s，说明 s 是 t 的子序列
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    // 使用 while 循环来处理多组输入
    while (cin >> s >> t) {
        if (isSubsequence(s, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
