#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    // 初始化Testlib，并读取命令行参数
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);  // 操作总数 N
    int maxWeight = atoi(argv[2]);  // 最大重量 X 的范围

    printf("%d\n", N);

    for (int i = 0; i < N; i++) {
        int op = rnd.next(0, 2);  // 生成操作类型：0 (入库), 1 (出库), 2 (查询)
        if (op == 0) {
            // 入库操作，生成一个 1 到 maxWeight 的随机重量
            int weight = rnd.next(1, maxWeight);
            printf("0 %d\n", weight);
        } else if (op == 1) {
            // 出库操作
            printf("1\n");
        } else {
            // 查询操作
            printf("2\n");
        }
    }
    return 0;
}
