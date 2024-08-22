#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 提醒学生使用vector
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b;
    vector<int> s;
    b.push_back(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        b.push_back(a[i] - a[i - 1]);
    }
    // 把区间操作转换为对点的操作
    // 对 第2个元素 到第5个元素加1
    //  1 3 4 5 6 6 7 8 9 
    b[1] += 1;
    b[5] -= 1;
    // 对 第6个元素 到第8个元素加2
    b[5] += 2;
    b[8] -= 2;
    //  得到修改后的a
    s.push_back(b[0]);
    for (int i = 1; i < b.size(); i++)
    {
        s.push_back(s[i - 1] + b[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    } 
    return 0;
}