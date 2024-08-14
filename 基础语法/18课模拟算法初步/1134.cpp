/* 
题目描述

(1134) 汽水瓶
有这样一道智力题:“某商店规定:三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶,他最多
可以换多少瓶汽水喝?”答案是5瓶,方法如下:先用9个空瓶子换3瓶汽水,喝掉3瓶满的,喝完以后4
个空瓶子,用3个再换一瓶,喝掉这瓶满的,这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水,
喝掉这瓶满的,喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶,最多可以
换多少瓶汽水喝?

输入

一个正整数n(1≤n≤100),表示小张手上的空汽水瓶数

输出

一个正整数,表示最多可以喝的汽水瓶数

样例

输入
10

输出
5
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
int sum = 0;
    int shui,ping;
    /* shui = n/3;
    ping = n%3+shui;
    sum += shui; */
    ping = n;
    while(ping >= 3)
    {
        shui = ping/3;
        ping = shui+ping%3;
        sum = sum + shui;
    }
    if(ping == 2)
    {
        sum = sum + 1;
    }
    cout<<sum<<endl;
   return 0;
}
