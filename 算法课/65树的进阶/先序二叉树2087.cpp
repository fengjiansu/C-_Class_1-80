#include <iostream>
#include <string>
using namespace std;

// �ݹ麯����ͨ������ͺ�����������乹���������
void buildPreOrder(const string &inOrder, const string &postOrder, int inL, int inR, int postL, int postR) {
    if (inL > inR || postL > postR) return;  // �������Ϊ�գ�����

    // ������������һ��Ԫ���ǵ�ǰ�����ĸ��ڵ�
    char root = postOrder[postR];
    cout << root;  // ������ڵ㣨���������

    // ������������ҵ����ڵ��λ��
    int rootPos = inL;
    while (inOrder[rootPos] != root) rootPos++;

    // �����������Ĵ�С
    int leftSize = rootPos - inL;

    // �ݹ鴦��������
    buildPreOrder(inOrder, postOrder, inL, rootPos - 1, postL, postL + leftSize - 1);

    // �ݹ鴦��������
    buildPreOrder(inOrder, postOrder, rootPos + 1, inR, postL + leftSize, postR - 1);
}

int main() {
    string inOrder, postOrder;
    
    // ��������ͺ������
    cin >> inOrder >> postOrder;
    
    // ���õݹ麯������������������
    buildPreOrder(inOrder, postOrder, 0, inOrder.size() - 1, 0, postOrder.size() - 1);
    cout << endl;

    return 0;
}