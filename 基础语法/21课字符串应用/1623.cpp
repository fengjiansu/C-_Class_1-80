/* 
��Ŀ����

��������
3
Rock Scissors
Paper Paper
Rock Paper

(1623)ʯͷ���Ӳ�

ʯͷ���Ӳ�,��һ�ֲ�ȭ��Ϸ ��.�� ��Ϸ����:ʯͷ�����,����ʯͷ,����������
����,��Ҫ��дһ���������ж�ʯͷ���Ӳ���Ϸ�Ľ����

����
��һ����һ������N,��ʾһ��������N����Ϸ��1��N��100��
������N�е�ÿһ�а��������ַ���,��ʾ��Ϸ������Player1,Player2��ѡ��(ʯͷ�����ӻ�
���ǲ�):S1 S2
�ַ���֮���Կո����S1,S2ֻ����ȡֵ��{"Rock","Scissors","Paper"}(��Сд����)�С�
���
�������N��,ÿһ�ж�Ӧһ��ʤ����(Player1����Player2),������Ϸ����ƽ��,�����Tie��

�������
Player1
Tie
Player2

˼·:һ����3�ֽ��,ÿ�ֽ��
��Ӧ�ĳ�ȭ�����Ҫ�ж�һ�¡�
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
