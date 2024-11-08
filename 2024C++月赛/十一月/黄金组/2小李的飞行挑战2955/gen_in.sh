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
6
4 7 8 6 3 2
EOF
let test_num++

# 测试点 2：小规模，有高有低
echo "生成测试点 $test_num：小规模，有高有低"
cat > test_cases/test$test_num.in << EOF
1
0
EOF
let test_num++

# 测试点 3：全高分题目
echo "生成测试点 $test_num：全高分题目"
cat > test_cases/test$test_num.in << EOF
1
30
EOF
let test_num++

# 测试点 4：随机分数
echo "生成测试点 $test_num：随机分数"
cat > test_cases/test$test_num.in << EOF
1
99999999999999
EOF
let test_num++

# 测试点 5：分数递增
echo "生成测试点 $test_num：分数递增"
cat > test_cases/test$test_num.in << EOF
5
99999999999999 2 4 5 6
EOF
let test_num++

# 测试点 6：分数递增
echo "生成测试点 $test_num：分数递增"
cat > test_cases/test$test_num.in << EOF
5
0 0 0 0 0
EOF

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
