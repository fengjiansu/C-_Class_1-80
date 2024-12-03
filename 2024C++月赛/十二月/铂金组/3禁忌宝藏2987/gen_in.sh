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
2 2
1 2
EOF
let test_num++

# 测试点 2：小规模，有禁忌规则
echo "生成测试点 $test_num：小规模，有禁忌规则"
cat > test_cases/test$test_num.in << EOF
3 2
1 2 3
EOF
let test_num++

# 测试点 3：小规模，无禁忌规则
echo "生成测试点 $test_num：小规模，无禁忌规则"
cat > test_cases/test$test_num.in << EOF
3 2
1 3 5
EOF
let test_num++

# 测试点 4：中等规模，间隔较大
echo "生成测试点 $test_num：中等规模，间隔较大"
cat > test_cases/test$test_num.in << EOF
5 3
1 3 5 7 9
EOF
let test_num++

# 测试点 5：中等规模，部分距离很大
echo "生成测试点 $test_num：中等规模，部分距离很大"
cat > test_cases/test$test_num.in << EOF
6 3
1 2 10 12 15 20
EOF
let test_num++

# 测试点 6：大规模，随机分布
echo "生成测试点 $test_num：大规模，随机分布"
cat > test_cases/test$test_num.in << EOF
10 5
1 2 3 10 20 50 80 100 200 300
EOF
let test_num++

# 测试点 7：最大坐标差
echo "生成测试点 $test_num：最大坐标差"
cat > test_cases/test$test_num.in << EOF
10 5
1 100 1000 10000 100000 1000000 10000000 100000000 1000000000 10000000000
EOF
let test_num++

# 测试点 8：高度相差小
echo "生成测试点 $test_num：高度相差小"
cat > test_cases/test$test_num.in << EOF
4 2
1 1 2 2
EOF
let test_num++

# 测试点 9：非常大的数据
echo "生成测试点 $test_num：非常大的数据"
cat > test_cases/test$test_num.in << EOF
50 10
EOF
for i in $(seq 1 50); do
    echo -n "$((i*100000)) " >> test_cases/test$test_num.in
done
let test_num++

# 测试点 10：间隔非常大的数据
echo "生成测试点 $test_num：间隔非常大的数据"
cat > test_cases/test$test_num.in << EOF
100 10
EOF
for ((i=1; i<=100; i++)); do
    echo -n "$((i*100000000)) " >> test_cases/test$test_num.in
done
let test_num++

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
