/* 

 */
#include <bits/stdc++.h>

using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // ��ʾ�з����ƫ��
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // ��ʾ�з����ƫ��
char grid[105][105]; // �����Դ�Ķ�ά�����ֹԽ��
int main()
{
   
   int n, m;
    cin >> n >> m;
    
    // ��ȡ��������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // ����ÿ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                cout << '*'; // ���׸�ֱ�����
            } else {
                int mineCount = 0;
                // �����Χ8������
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    // �ж��Ƿ�Խ�缰�Ƿ�Ϊ����
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*') {
                        mineCount++;
                    }
                }
                cout << mineCount; // �����Χ��������
            }
        }
        cout << endl;
    }
   return 0;
}
