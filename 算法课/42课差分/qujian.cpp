#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ����ѧ��ʹ��vector
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b;
    vector<int> s;
    b.push_back(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        b.push_back(a[i] - a[i - 1]);
    }
    // ���������ת��Ϊ�Ե�Ĳ���
    // �� ��2��Ԫ�� ����5��Ԫ�ؼ�1
    //  1 3 4 5 6 6 7 8 9 
    b[1] += 1;
    b[5] -= 1;
    // �� ��6��Ԫ�� ����8��Ԫ�ؼ�2
    b[5] += 2;
    b[8] -= 2;
    //  �õ��޸ĺ��a
    s.push_back(b[0]);
    for (int i = 1; i < b.size(); i++)
    {
        s.push_back(s[i - 1] + b[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    } 
    return 0;
}