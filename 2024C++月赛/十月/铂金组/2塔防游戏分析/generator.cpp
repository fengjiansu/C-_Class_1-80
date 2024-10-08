#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    // ��ʼ��Testlib������ȡ�����в���
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);  // �������� N
    int maxWeight = atoi(argv[2]);  // ������� X �ķ�Χ

    printf("%d\n", N);

    for (int i = 0; i < N; i++) {
        int op = rnd.next(0, 2);  // ���ɲ������ͣ�0 (���), 1 (����), 2 (��ѯ)
        if (op == 0) {
            // ������������һ�� 1 �� maxWeight ���������
            int weight = rnd.next(1, maxWeight);
            printf("0 %d\n", weight);
        } else if (op == 1) {
            // �������
            printf("1\n");
        } else {
            // ��ѯ����
            printf("2\n");
        }
    }
    return 0;
}
