/* 
题目描述

输入样例
3
Rock Scissors
Paper Paper
Rock Paper

(1623)石头剪子布

石头剪子布,是一种猜拳游戏 ….… 游戏规则:石头打剪刀,布包石头,剪刀剪布。
现在,需要你写一个程序来判断石头剪子布游戏的结果。

输入
第一行是一个整数N,表示一共进行了N次游戏。1≤N≤100。
接下来N行的每一行包括两个字符串,表示游戏参与者Player1,Player2的选择(石头、剪子或
者是布):S1 S2
字符串之间以空格隔开S1,S2只可能取值在{"Rock","Scissors","Paper"}(大小写敏感)中。
输出
输出包括N行,每一行对应一个胜利者(Player1或者Player2),或者游戏出现平局,则输出Tie。

输出样例
Player1
Tie
Player2

思路:一共有3种结果,每种结果
对应的出拳情况都要判断一下。
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string player1, player2;
        cin >> player1 >> player2;

        if (player1 == player2) {
            cout << "Tie" << endl;
        } else if ((player1 == "Rock" && player2 == "Scissors") ||
                   (player1 == "Scissors" && player2 == "Paper") ||
                   (player1 == "Paper" && player2 == "Rock")) {
            cout << "Player1" << endl;
        } else {
            cout << "Player2" << endl;
        }
    }
    return 0;
}
