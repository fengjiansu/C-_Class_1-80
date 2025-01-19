/* 

小明是一位图书管理员，书架上总共有从左到右依次排列好的N本书（依次用书籍编号1～N表示），每本书属于M种类别（用类别编号1～M表示）之一。小明想要将这些书重新排列，使得所有书按类别编号由小到大排列，同一类别的书籍排列在一起，且同一类别中书籍的相对顺序必须保持与原书架上的顺序一致。

你的任务是帮助小明完成这个任务，并输出整理后的书籍顺序。

输入
第一行，用空格隔开的两个正整数N和M（1 ≤M ≤ N ≤ 10^5），表示书的总数量和类别数。

第二行，N个用空格隔开的整数Gi（1 ≤ Gi ≤ M），表示按从左到右的原顺序的每本书的类别。

输出
N个用空格隔开的整数，表示重新排列后的所有书的编号顺序
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    vector<int> g_list(n); // 存储每本书的类别
    for (int i = 0; i < n; i++) {
        cin >> g_list[i];
    }

    // 初始化桶（分组），每个类别用一个 vector 存储对应的书籍编号
    vector<vector<int>> buckets(m + 1);

    // 将书籍编号按类别分组
    for (int i = 0; i < n; i++) {
        buckets[g_list[i]].push_back(i + 1); // 书籍编号是从1开始
    }

    // 输出按类别顺序排列的书籍编号
    for (int category = 1; category <= m; category++) {
        for (int id : buckets[category]) {
            cout << id << " ";
        }
    }
    cout << endl;

    return 0;
}