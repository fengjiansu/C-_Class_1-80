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
100 100 100 100 100 100 100 100 100 100
100
EOF
let test_num++

# 测试点 2：小规模，有高有低
echo "生成测试点 $test_num：小规模，有高有低"
cat > test_cases/test$test_num.in << EOF
120 130 150 160 170 180 190 200 110 115
115
EOF
let test_num++

# 测试点 3：全高物品
echo "生成测试点 $test_num：全高物品"
cat > test_cases/test$test_num.in << EOF
200 200 200 200 200 200 200 200 200 200
120
EOF
let test_num++

# 测试点 4：随机高度
echo "生成测试点 $test_num：随机高度"
cat > test_cases/test$test_num.in << EOF
150 140 130 120 110 100 160 170 180 190
110
EOF
let test_num++

# 测试点 5：高度递增
echo "生成测试点 $test_num：高度递增"
cat > test_cases/test$test_num.in << EOF
100 110 120 130 140 150 160 170 180 190
105
EOF


echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"