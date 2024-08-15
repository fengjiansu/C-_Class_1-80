/* 
在英语作为外语考试（TOEFL）中，听力部分非常重要，但对大多数学生而言也很困难，因为通常很难记住整个段落。为了帮助自己记住内容，学生可以写下一些必要的细节。然而，由于其长度，写下完整的单词并不容易。这就是为什么我们决定使用缩写来表达整个单词的原因。
缩写很容易，我们要做的就是保留辅音并抹去元音。在英语字母中，我们将“ a”，“ e”，“ i”，“ y”，“ o”，“ u”视为元音，并将其他字母视为辅音。例如，“subconscious”将表示为“ sbcnscs”。
但是，有一个例外：如果元音作为第一个字母出现，则应保留它们而不是将它们扔掉。例如，“ oipotato”应表示为“ optt”。
既然您已经学习了如何使用缩写方法，那么该进行一些练习了。现在，我们给你一些单词，你需要输出它的缩写。
输入格式：
第一行一个t，表示有t组测试数据，接下来t行每行一个小写字母组成的单词
s(1≤∣s∣≤100)
输出
输出t行表示答案
5
subconscious
oipotato
word
symbol
apple
输出
sbcnscs
optt
wrd
smbl
appl
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      string s;
      cin >> s;
      
      bool f = 1;
		for (auto &c : s)
		{
			if(f)
			{
				cout<<c;
				f = 0;
				continue;
			}
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||c=='y')
				continue;
			cout << c;
		}
		cout<<endl;
		
   }

   return 0;
}
