#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10; 
int pre[MAXN+1], nxt[MAXN+1];
// ���������еĽڵ���Ϊ1~N
// pre[i] = j ��ʾj��i�����
// nxt[i] = j ��ʾj��i���ұ�
// ��Ϊ-1��ʾû�ж�Ӧ���ھ�

// ��ʼ����ֻ��һ���ڵ�1
// pre[1] = -1, nxt[1] = -1
void init() {
    pre[1] = -1;
    nxt[1] = -1;
}

// ��k���ұ߲���x
void insertAfter(int k, int x) {
    int R = nxt[k];   // k�����ھ�
    nxt[k] = x;
    pre[x] = k;
    nxt[x] = R;
    if (R != -1) {
        pre[R] = x;
    }
}

// ��k����߲���x
void insertBefore(int k, int x) {
    int L = pre[k];    // k�����ھ�
    pre[x] = L;
    nxt[x] = k;
    pre[k] = x;
    if (L != -1) {
        nxt[L] = x;
    }
}

// ����IDɾ���ڵ�x
void removeByID(int x) {
    int L = pre[x], R = nxt[x];
    if (L != -1) nxt[L] = R;
    if (R != -1) pre[R] = L;
    // ��x���������Ƴ�
    pre[x] = -1;
    nxt[x] = -1;
}

// �������ڵ㿪ʼ��ӡ��ǰ����
void printListFromLeft() {
    // �������ڵ�
    int start = 1;
    while (pre[start] != -1) {
        start = pre[start];
    }

    // ��start���ұ������
    for (int cur = start; cur != -1; cur = nxt[cur]) {
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ��ʼ��ֻ���ڵ�1��˫������
    init();

    // �������һЩ�ڵ���ԣ�
    // ��1�ұ߲���2������Ϊ 1 -> 2
    insertAfter(1, 2);
    // ��1��߲���3������Ϊ 3 -> 1 -> 2
    insertBefore(1, 3);
    // ��2�ұ߲���4������Ϊ 3 -> 1 -> 2 -> 4
    insertAfter(2, 4);

    // ɾ���ڵ�2�������Ϊ 3 -> 1 -> 4
    removeByID(2);

    // ��ӡ��ǰ����3 1 4
    printListFromLeft();

    return 0;
}
