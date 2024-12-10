#include <bits/stdc++.h>
using namespace std;

static int L[100000+5], R[100000+5]; // left[i], right[i] �ֱ��ʾ i��ͬѧ�������ڵı��
static bool removed[100000+5];       // ���ĳ��ͬѧ�Ƿ��ѱ��Ƴ�

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    // ��ʼ����ֻ��1��ͬѧ
    // 1�����Ҷ�Ϊ-1����ʾֻ��1��һ�����ڶ�����
    L[1] = -1;
    R[1] = -1;

    // ��2��ͬѧ��ʼ����
    for (int i = 2; i <= N; i++) {
        int k, p; cin >> k >> p;
        if (p == 0) {
            // i���뵽k�����
            int leftNeighbor = L[k];  // k�����ھ�
            L[i] = leftNeighbor;      // i����Ϊԭ����leftNeighbor
            R[i] = k;                 // i����Ϊk
            L[k] = i;                 // k����Ϊi
            if (leftNeighbor != -1) {
                R[leftNeighbor] = i;  // ԭ���ھӵ��Ҹ�Ϊi
            }
        } else {
            // i���뵽k���ұ�
            int rightNeighbor = R[k]; // k�����ھ�
            R[i] = rightNeighbor;     // i����Ϊԭ����rightNeighbor
            L[i] = k;                 // i����Ϊk
            R[k] = i;                 // k����Ϊi
            if (rightNeighbor != -1) {
                L[rightNeighbor] = i; // ԭ���ھӵ����Ϊi
            }
        }
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        if (!removed[x]) {
            // ɾ��x��ͬѧ
            int leftN = L[x];
            int rightN = R[x];
            if (leftN != -1) R[leftN] = rightN;
            if (rightN != -1) L[rightN] = leftN;
            removed[x] = true;
        }
    }

    // �ҵ�������ͬѧ
    int start = 1;
    // ���������ҵ������
    while (L[start] != -1) {
        start = L[start];
    }

    // ��start��ʼ�������δ��ɾ����ͬѧ
    // �п���start�Ѿ���ɾ���ˣ�����Ҫ�ҵ���һ��δɾ�������ұߵ�ͬѧ
    while (start != -1 && removed[start]) {
        start = R[start];
    }

    // ˳��rightָ�����
    bool first = true;
    for (int cur = start; cur != -1; cur = R[cur]) {
        if (!removed[cur]) {
            if (!first) cout << " ";
            cout << cur;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}