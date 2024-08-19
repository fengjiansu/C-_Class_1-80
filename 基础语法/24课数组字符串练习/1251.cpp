/* 
(1251)解密

题目描述
给你个加密的单词和加密规则表,你需要将它解码后
输出。
加密的规则很简单:将原文章中的每个字母都改成加
密表中对应的字母,例如对于下表:
原字符abcdefghijklmnopqrstuvwxy
Z
加密后zyxwvutsrqponmlkjihgfedcb

加密前如果是:good
则加密后将是:tllw

a

输入
第一行26个字符,分别表示a-z加密后的字符。
第二行加密后的单词(长度不超过100,并且只包含小写字母)。
输出
一行,表示解密后的单词(也将是原单词)。
输入样例
zyxwvutsrqponmlkjihgfedcba
tllw

输出样例
good

 */
#include <bits/stdc++.h>

using namespace std;

char code[27];
char str[105];
// 主函数
int main()
{
    char c; // 定义一个字符变量用于输入
    // 初始化一个长度为26的数组，用于存储字母的替换关系
    for(int i=0; i<26; i++)
    {
        cin >> c; // 输入一个字符
        // 建立从'a'到'z'的字符替换关系
        code[c-'a'] = 'a' + i;
    }
    cin >> str; // 输入一个字符串
    // 遍历字符串，根据替换关系进行字符替换
    for(int i=0; i<strlen(str); i++)
    {
        str[i] = code[str[i] - 'a'];
    }
    cout << str; // 输出替换后的字符串
    return 0; // 程序结束，返回0
}
