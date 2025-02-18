/*
(1266)小书童-凯撒密码

某蒟蒻迷上了“小书童”,有一天登录时忘记密码了(他没绑定邮箱or手机),于是便把问题抛给了
神犇你。蒟蒻虽然忘记密码,但他还记得密码是由一个字符串组成。密码是由原文字符串(由不超过
50个小写字母组成)中每个字母向后移动n位形成的。z的下一个字母是a,如此循环。他现在找到
了移动前的原文字符串及n,请你求出密码。

输入
第一行一个整数n(0≤n≤10)。
第二行一个长度不超过50的字符串。

输出
输出密码。
输入样例

abc

输出样例
bcd

 */
#include <bits/stdc++.h>

using namespace std;

char s[55];
int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < strlen(s); i++)
    {
        /*  s[i]=s[i]+n;
         if(s[i]>'z')
         {
             s[i]=s[i]-26;
         } */
        // 计算新字符
        /*
        s[i] - 'a'：计算字符相对于 'a' 的偏移量（0 表示 'a'，1 表示 'b'，以此类推）。
        + n：将字符向后移动 n 位。
        % 26：确保字符在超过 'z' 后回到 'a'。
        + 'a'：将计算后的结果转换回字符。
         */
        s[i] = (s[i] - 'a' + n) % 26 + 'a';
    }
    cout << s << endl;
    return 0;
}
