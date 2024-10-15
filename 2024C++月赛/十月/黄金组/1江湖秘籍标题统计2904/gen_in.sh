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
234
EOF
let test_num++

# 测试点 2：小规模，有解情况
echo "生成测试点 $test_num：小规模，有解情况"
cat > test_cases/test$test_num.in << EOF
CA 45
EOF
let test_num++

# 测试点 3：小规模，无解情况
echo "生成测试点 $test_num：小规模，无解情况"
cat > test_cases/test$test_num.in << EOF
12345
EOF
let test_num++

# 测试点 4：中等规模，随机数据
echo "生成测试点 $test_num：中等规模，随机数据"
cat > test_cases/test$test_num.in << EOF
12aA21j
EOF
let test_num++

# 测试点 5：大规模，有解和无解混合
echo "生成测试点 $test_num：大规模，有解和无解混合"
cat > test_cases/test$test_num.in << EOF
1 2d gdsa 
EOF



echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
