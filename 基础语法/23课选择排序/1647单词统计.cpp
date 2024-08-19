/* 
题目描述

(1647)单词统计

给定一个包含若干个单词(全为小写)的字符串,单词间用一个或多个#
隔开,统计单词个数。

输入
输入一个字符串。
输出
输出单词个数。
输入样例
apple###ice##cream
输出样例
3
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
   string str;
    cin >> str; // 输入字符串

    int word_count = 0;
    bool in_word = false; // 标志当前是否处于单词中

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // 如果当前字符是字母，说明在单词中
            if (!in_word) {
                in_word = true; // 标记进入单词
                word_count++; // 单词数加1
            }
        } else {
            // 当前字符不是字母，说明可能遇到分隔符
            in_word = false; // 退出单词
        }
    }

    cout << word_count << endl; // 输出单词数

   return 0;
}
