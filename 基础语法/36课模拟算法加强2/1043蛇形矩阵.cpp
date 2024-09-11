/* 
E. 蛇形矩阵
描述
在n×n方阵内填入1,2,3,...,n×n，要求填成蛇形,具体看样例

输入
一个整数
n(1≤n≤10)
n(1≤n≤10)

输出

n×n的矩阵
样例
输入
4
输出
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4

 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));  // 初始化 n×n 矩阵
    
    int num = 1;  // 从 1 开始填充
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    
    while (num <= n * n) {
        
        
        // 从上到下填充最右边的一列
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;  // 最右边一列填完，向左移动
        
        // 从右到左填充最下面的一行
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;  // 最下面一行填完，向上移动
        }
        
        // 从下到上填充最左边的一列
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;  // 最左边一列填完，向右移动
        }
        // 从左到右填充最上面的一行
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;  // 最上面一行填完，向下移动
    }
    
    // 输出蛇形矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
