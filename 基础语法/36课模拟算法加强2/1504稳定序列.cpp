/* 
D.稳定序列
描述

给定一个序列,一次转换是将一个数变成这个数在这个序列中出现的次数。

序列{2,1,1,4,3,1,2}中,2出现2次,1出现3次,3和4出现1次,那么这个序列进行
一次转换之后就变成了{2,3,3,1,1,3,2},同理,进行两次转换后是{2,3,3,2,2,3,2},进行
三次转换后是{4,3,3,4,4,3,4}。之后这个序列就不会发生变化了。

输入一个序列,求最后稳定之后的序列是怎么样的。

输入

先输入n(n≤1000),然后下面一行输入n个正整数,保证每个数≤n

输出

输出最后稳定后的序列
样例
输入
7
2 1 1 4 3 1 2
输出
4 3 3 4 4 3 4
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

// 使用桶计数法计算序列的转换
vector<int> transform(const vector<int>& seq, int n) {
    vector<int> bucket(n + 1, 0);  // 创建桶数组，大小为 n+1，初始值为 0
    vector<int> result(seq.size());

    // 统计每个元素的出现次数
    for (int num : seq) {
        bucket[num]++;
    }

    // 构造转换后的序列
    for (int i = 0; i < seq.size(); i++) {
        result[i] = bucket[seq[i]];
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);

    // 输入序列
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    // 不断进行转换，直到序列稳定
    while (true) {
        vector<int> new_seq = transform(seq, n);

        // 检查当前序列是否稳定
        if (new_seq == seq) {
            break;
        }

        // 更新当前序列
        seq = new_seq;
    }

    // 输出稳定后的序列
    for (int i = 0; i < n; i++) {
        cout << seq[i] << " ";
    }

    return 0;
}
