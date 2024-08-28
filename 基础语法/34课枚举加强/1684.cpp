/* 
题目描述

(1684)统计方形

有一个nxm方格的棋盘,求其方格包含多少正方形、长方形(不包含正方形)。

输入
一行,两个正整数n,m(n≤50,m≤50)。

输出
一行,两个正整数,分别表示方格包含多少正方形、长方形(不包含正方形)。

输入样例
23

输出样例
8 10

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
    /* 
    棋盘上，不是同行同列的两个点就能确定一个方形
    让学生说一下左上角顶点和右下角顶点的行列值的范围。
    用i，j分别表示左上角顶点的行列值，
    p，q分别表示右下角顶点的行列值。

    */
    int n, m;
    cin>>n>>m;
    int x=0,y=0;
    /* 四重循环会超时
        for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int p=i+1;p<=n;p++)
            {
                for(int q=j+1;q<=m;q++)
                {
                    if(abs(i-p) == abs(j-q))
                    {
                        x++;
                    }
                    else
                    {
                        y++;
                    }
                }
            }
        }
    } */
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(i==j) x+=(n-i+1)*(m-j+1);
           else y+=(n-i+1)*(m-j+1);
       }
   }
   cout<<x<<" "<<y<<endl;
    return 0;
}
