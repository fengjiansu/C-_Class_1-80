/* 
E.分形
描述

#include <iostream>

using namespace std;


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
// 函数递归构建 B(n)
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<char>> &flag,int x,int y,int n){
    if(n==1){
        flag[x][y]='X';
        return;
    }
    //对于n-1的图形,每个小图的长度是
    int k = pow(3,n-2);// 计算当前递归层的偏移量
    solve(flag,x,y,n-1);    // 左上
    solve(flag,x,y+2*k,n-1);// 右上
    solve(flag,x+k,y+k,n-1);// 中间
    solve(flag,x+2*k,y,n-1); // 左下
    solve(flag,x+2*k,y+2*k,n-1);// 右下
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> flag(pow(3,n-1),vector<char>(pow(3,n-1),' '));

    solve(flag,0,0,n);
    
    for(int i=0;i<pow(3,n-1);i++){
        for(int j=0;j<pow(3,n-1);j++){
            cout << flag[i][j];
        }
        cout << endl;
    }
    return 0;
}
