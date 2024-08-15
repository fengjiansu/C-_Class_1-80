/* 
海亮素侦教育

(1628)幸运车牌号

小明去车管所办理车牌号,电脑随机生成n个五位数车牌号可供选择,如果车牌号出现数字
8或者尾号是他的幸运字母M,他就会选择这个号码,否则他就会选择最后一个号码。请输
出小明选中的号码(选号时间有限,小明遇到第一个符合的号码就会选中它)。

输入
第一行一个正整数n,表示生成车牌号的个数。
接下来n行,每行一个字符串,包含五个字符,保证字符只有大写字母或数字。

输出
一行字符串,表示小明选中的车牌号。

输入样例
3
322M5
82H22
FF666

题目描述

输出样例
82H22
 */
#include <bits/stdc++.h>

using namespace std;

char s[10];
int main()
{
   int n;
   cin>>n;
   bool f=0;
   while(n--)
   {
       cin>>s;
       if(s[4]=='M')
       {
           cout<<s<<endl;
           f = 1;
           break;
       }
       for(int i=0;i<5;i++)
       {
        if(s[i]=='8')
        {
            cout<<s<<endl;
            f = 1;
            break;
        }
       }
       //注意for循环中break只能跳出一层
       if (f) break;
   }
   if(f==0) cout<<s<<endl;
   return 0;
}
