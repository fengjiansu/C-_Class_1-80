/* 
��Ŀ����

(1647)����ͳ��

����һ���������ɸ�����(ȫΪСд)���ַ���,���ʼ���һ������#
����,ͳ�Ƶ��ʸ�����

����
����һ���ַ�����
���
������ʸ�����
��������
apple###ice##cream
�������
3
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
   string str;
    cin >> str; // �����ַ���

    int word_count = 0;
    bool in_word = false; // ��־��ǰ�Ƿ��ڵ�����

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // �����ǰ�ַ�����ĸ��˵���ڵ�����
            if (!in_word) {
                in_word = true; // ��ǽ��뵥��
                word_count++; // ��������1
            }
        } else {
            // ��ǰ�ַ�������ĸ��˵�����������ָ���
            in_word = false; // �˳�����
        }
    }

    cout << word_count << endl; // ���������

   return 0;
}
