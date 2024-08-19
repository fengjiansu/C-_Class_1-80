/* 

 */
#include <bits/stdc++.h>

using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 表示行方向的偏移
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 表示列方向的偏移
char grid[105][105]; // 定义稍大的二维数组防止越界
int main()
{
   
   int n, m;
    cin >> n >> m;
    
    // 读取雷区数据
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 遍历每个格子
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                cout << '*'; // 地雷格直接输出
            } else {
                int mineCount = 0;
                // 检查周围8个格子
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    // 判断是否越界及是否为地雷
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*') {
                        mineCount++;
                    }
                }
                cout << mineCount; // 输出周围地雷数量
            }
        }
        cout << endl;
    }
   return 0;
}
