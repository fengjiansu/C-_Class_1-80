/* 
E. ���ξ���
����
��n��n����������1,2,3,...,n��n��Ҫ���������,���忴����

����
һ������
n(1��n��10)
n(1��n��10)

���

n��n�ľ���
����
����
4
���
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
    
    vector<vector<int>> matrix(n, vector<int>(n, 0));  // ��ʼ�� n��n ����
    
    int num = 1;  // �� 1 ��ʼ���
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    
    while (num <= n * n) {
        
        
        // ���ϵ���������ұߵ�һ��
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;  // ���ұ�һ�����꣬�����ƶ�
        
        // ���ҵ�������������һ��
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;  // ������һ�����꣬�����ƶ�
        }
        
        // ���µ����������ߵ�һ��
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;  // �����һ�����꣬�����ƶ�
        }
        // ����������������һ��
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;  // ������һ�����꣬�����ƶ�
    }
    
    // ������ξ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
