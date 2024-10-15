#!/bin/bash


# 编译生成器
g++ -ID:\\C++_Code\\testlib generator.cpp -o generator

# 生成测试点 1: 最小输入
echo "生成测试点 1"
./generator 1 1 > test1.in

# 生成测试点 2: 仅有入库操作
echo "生成测试点 2"
./generator 10 10 > test2.in

# 生成测试点 3: 出库后查询
echo "生成测试点 3"
./generator 10 100 > test3.in

# 生成测试点 4: 所有出库操作无效
echo "生成测试点 4"
./generator 10 100 > test4.in

# 生成测试点 5: 最大数量的小集装箱
echo "生成测试点 5"
./generator 1000 1000 > test5.in

# 生成测试点 6: 混合操作，含随机和构造
echo "生成测试点 6"
./generator 1000 1000000 > test6.in

# 生成测试点 7: 构造极限数据
echo "生成测试点 7"
./generator 2000 1000 > test7.in

# 生成测试点 8: 最大随机输入
echo "生成测试点 8"
./generator 1000 10000 > test8.in

# 生成测试点 9: 所有查询无效
echo "生成测试点 9"
./generator 1000 1000 > test9.in

# 生成测试点 10: 整数溢出检测
echo "生成测试点 10"
./generator 100 100000 > test10.in

echo "所有测试点生成完毕！"
