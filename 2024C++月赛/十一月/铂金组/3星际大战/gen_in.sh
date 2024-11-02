#!/bin/bash

# 赋予脚本可执行权限：chmod +x generate_tests.sh

# 创建一个目录来存放测试点
mkdir -p test_cases

# 测试点计数器
test_num=2

echo "开始生成测试点..."

# 测试点 1：最小输入规模
echo "生成测试点 $test_num：最小输入规模"
cat > test_cases/test$test_num.in << EOF
3
1 1 1
2 3 1 1
EOF
let test_num++

# 测试点 2：小规模，有高有低
echo "生成测试点 $test_num：小规模，有高有低"
cat > test_cases/test$test_num.in << EOF
5
2 2 2 2 2
3 2 1 1
EOF
let test_num++

# 测试点 3：全高物品
echo "生成测试点 $test_num：全高物品"
cat > test_cases/test$test_num.in << EOF
5
5 4 3 2 1
3 5 10 3
EOF
let test_num++

# 测试点 4：随机高度
echo "生成测试点 $test_num：随机高度"
cat > test_cases/test$test_num.in << EOF
6
2 3 4 5 6 7
4 4 10 5
EOF
let test_num++

# 测试点 5：高度递增
echo "生成测试点 $test_num：高度递增"
cat > test_cases/test$test_num.in << EOF
7
10 10 10 0 1 1 1
4 1 5 1
EOF


echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"