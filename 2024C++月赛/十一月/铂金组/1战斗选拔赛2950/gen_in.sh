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
2 1
5
10
EOF
let test_num++

# 测试点 2：小规模，有高有低
echo "生成测试点 $test_num：小规模，有高有低"
cat > test_cases/test$test_num.in << EOF
3 2
10 20
5 25
1 30
EOF
let test_num++

# 测试点 3：全高分题目
echo "生成测试点 $test_num：全高分题目"
cat > test_cases/test$test_num.in << EOF
4 3
50 50 50
50 50 50
50 50 50
50 50 50
EOF
let test_num++

# 测试点 4：随机分数
echo "生成测试点 $test_num：随机分数"
cat > test_cases/test$test_num.in << EOF
5 4
10 15 20 25
30 5 10 40
25 30 15 20
35 25 30 10
20 15 10 25
EOF
let test_num++

# 测试点 5：分数递增
echo "生成测试点 $test_num：分数递增"
cat > test_cases/test$test_num.in << EOF
6 2
1 2
3 4
5 6
7 8
9 10
11 12
EOF
let test_num++

# 测试点 6：分数递减
echo "生成测试点 $test_num：分数递减"
cat > test_cases/test$test_num.in << EOF
6 2
12 11
10 9
8 7
6 5
4 3
2 1
EOF
let test_num++

# 测试点 7：不同分数，多个最大值
echo "生成测试点 $test_num：不同分数，多个最大值"
cat > test_cases/test$test_num.in << EOF
4 3
20 30 10
30 20 10
10 30 20
20 10 30
EOF
let test_num++

# 测试点 8：相同分数
echo "生成测试点 $test_num：相同分数"
cat > test_cases/test$test_num.in << EOF
5 3
10 10 10
10 10 10
10 10 10
10 10 10
10 10 10
EOF
let test_num++

# 测试点 9：随机高分与低分混合
echo "生成测试点 $test_num：随机高分与低分混合"
cat > test_cases/test$test_num.in << EOF
7 2
15 5
10 30
20 25
5 10
30 20
25 15
10 5
EOF
let test_num++

# 测试点 10：边界测试
echo "生成测试点 $test_num：边界测试"
cat > test_cases/test$test_num.in << EOF
100 10
$(for i in $(seq 1 100); do echo $((RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)) $(($RANDOM % 100 + 1)); done)
EOF
let test_num++

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
