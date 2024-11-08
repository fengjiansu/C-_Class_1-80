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
2
3
5
EOF
let test_num++

# 测试点 2：小规模，有高有低
echo "生成测试点 $test_num：小规模，有高有低"
cat > test_cases/test$test_num.in << EOF
3
100
100
100
EOF
let test_num++

# 测试点 3：全高分题目
echo "生成测试点 $test_num：全高分题目"
cat > test_cases/test$test_num.in << EOF
4
100
100
100
2
EOF
let test_num++

# 测试点 4：随机分数
echo "生成测试点 $test_num：随机分数"
cat > test_cases/test$test_num.in << EOF
1
1
EOF
let test_num++

# 测试点 5：分数递增
echo "生成测试点 $test_num：分数递增"
cat > test_cases/test$test_num.in << EOF
1
100
EOF
let test_num++



echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
