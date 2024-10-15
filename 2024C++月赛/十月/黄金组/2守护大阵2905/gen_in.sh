#!/bin/bash

# 赋予脚本可执行权限：chmod +x generate_tests.sh

# 创建一个目录来存放测试点
mkdir -p test_cases

# 测试点计数器
test_num=1

echo "开始生成测试点..."

# 测试点 1：最小输入规模
echo "生成测试点 $test_num：最小输入规模"
cat > test_cases/test$test_num.in << EOF
1 1
5
EOF
let test_num++

# 测试点 2：小规模矩阵
echo "生成测试点 $test_num：小规模矩阵"
cat > test_cases/test$test_num.in << EOF
2 2
1 2
3 4
EOF
let test_num++

# 测试点 3：边界值测试
echo "生成测试点 $test_num：边界值测试"
cat > test_cases/test$test_num.in << EOF
3 3
3 4 5
6 7 8
9 10 11
EOF
let test_num++

# 测试点 4：较大矩阵
echo "生成测试点 $test_num：较大矩阵"
cat > test_cases/test$test_num.in << EOF
4 4
1 1 1 1
1 2 2 1
1 2 2 1
1 1 1 1
EOF
let test_num++

# 测试点 5：随机数据
echo "生成测试点 $test_num：随机数据"
cat > test_cases/test$test_num.in << EOF
5 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
EOF


echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"