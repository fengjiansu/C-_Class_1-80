#include<bits/stdc++.h>
using namespace std;

int main() {
    int c1, m1;  // ��һ��Ͱ��������ţ����
    int c2, m2;  // �ڶ���Ͱ��������ţ����
    int c3, m3;  // ������Ͱ��������ţ����

    cin >> c1 >> m1;  // �����һ��Ͱ��������ţ����
    cin >> c2 >> m2;  // ����ڶ���Ͱ��������ţ����
    cin >> c3 >> m3;  // ���������Ͱ��������ţ����

    for(int i = 0; i < 100; i++) {
        if(i % 3 == 0) {  // ��һ�λ���ĴΡ��� ��97�ν�Ͱ1����Ͱ2
            int pour = min(m1, c2 - m2);
            m1 -= pour;
            m2 += pour;
        } else if(i % 3 == 1) {  // �ڶ��λ����Ρ��� ��98�ν�Ͱ2����Ͱ3
            int pour = min(m2, c3 - m3);
            m2 -= pour;
            m3 += pour;
        } else {  // �����λ�����Ρ��� ��99�ν�Ͱ3����Ͱ1
            int pour = min(m3, c1 - m1);
            m3 -= pour;
            m1 += pour;
        }
    }

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    return 0;
}