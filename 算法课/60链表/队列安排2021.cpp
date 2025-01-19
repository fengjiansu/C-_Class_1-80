#include <bits/stdc++.h>
using namespace std;

// �����ܵ�����
static const int MAXN = 100000 + 5;

int Lch[MAXN], Rch[MAXN]; // �ֱ�洢ÿ���˵����ں�����
bool inQueue[MAXN];       // ��Ǹñ�ŵ�ͬѧ�Ƿ����ڶ���

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // ��ʼ����ֻ�� 1 ��ͬѧ�ڶ�����
    int head = 1;
    Lch[1] = 0;     // ��ʾ 1 ���������
    Rch[1] = 0;     // ��ʾ 1 ���ұ�����
    inQueue[1] = true;

    // �� 2 �ſ�ʼ�������
    for (int i = 2; i <= N; i++) {
        int k, p;
        cin >> k >> p; // ����Ҫ���뵽 k ����� (p=0) ���ұ� (p=1)
        inQueue[i] = true;

        if (p == 0) {
            // ���뵽 k �����
            int leftK = Lch[k];
            Rch[i] = k;
            Lch[i] = leftK;

            // ��� k ԭ�������ڣ�����Ҫ����λ���ڵ����ڱ�Ϊ i
            if (leftK != 0) {
                Rch[leftK] = i;
            } else {
                // k ԭ���Ƕ�������ˣ����� i ��Ϊ�µ����
                head = i;
            }
            // k �����ڸ���Ϊ i
            Lch[k] = i;

        } else {
            // ���뵽 k ���ұ�
            int rightK = Rch[k];
            Lch[i] = k;
            Rch[i] = rightK;

            // ��� k ԭ�������ڣ�����Ҫ����λ���ڵ����ڱ�Ϊ i
            if (rightK != 0) {
                Lch[rightK] = i;
            }
            // k �����ڸ���Ϊ i
            Rch[k] = i;
        }
    }

    // ����Ҫɾ����ͬѧ���� M
    int M;
    cin >> M;

    while (M--) {
        int x;
        cin >> x;

        // �� x �Ѿ����ڶ����У������
        if (!inQueue[x]) continue;

        // ����ִ��ɾ������
        inQueue[x] = false;
        int left = Lch[x], right = Rch[x];

        // �� x �����ں����ڻ�������
        if (left != 0) Rch[left] = right;
        if (right != 0) Lch[right] = left;

        // ��� x ǡ���� head����Ҫ���� head
        if (x == head) {
            head = right; // �� right Ϊ 0��������ѿ�
        }

        // ��� x ��ʧЧ����ѡ��
        Lch[x] = 0;
        Rch[x] = 0;
    }

    // ���� head ��ʼ���������ұ������
    int cur = head;
    bool firstPrint = true;
    while (cur != 0) {
        if (!firstPrint) cout << " ";
        firstPrint = false;
        cout << cur;
        cur = Rch[cur];
    }
    cout << "\n";

    return 0;
}
