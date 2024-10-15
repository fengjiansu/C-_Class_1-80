#!/bin/bash

# 编译生成器
g++ -ID:/C++_Code/testlib generator.cpp -o generator


# 生成测试点目录
mkdir -p test_cases

# 生成测试点 1: 最小输入
echo "生成测试点 1"
./generator 9 3 test_cases/test1.in

# 生成测试点 2: 较大输入
echo "生成测试点 2"
./generator 100 100 test_cases/test2.in

# 生成测试点 3: 大规模输入
echo "生成测试点 3"
./generator 1000 1000 test_cases/test3.in

# 生成测试点 4: 中等输入，圣峰学院学徒较少
echo "生成测试点 4"
./generator 100 3 test_cases/test4.in

# 生成测试点 5: 更多学徒，圣峰学院学徒较少
echo "生成测试点 5"
./generator 1000 3 test_cases/test5.in

# 生成测试点 6: 混合规模输入
echo "生成测试点 6"
./generator 9 3 test_cases/test6.in

echo "所有测试点生成完毕！"