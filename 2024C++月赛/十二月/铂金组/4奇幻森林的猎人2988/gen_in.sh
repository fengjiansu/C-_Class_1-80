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

# 测试点 2：小规模，简单的怪物强度
echo "生成测试点 $test_num：小规模，简单的怪物强度"
cat > test_cases/test$test_num.in << EOF
5 3
1 -10 2 -4 3
EOF
let test_num++

# 测试点 3：小规模，包含负值
echo "生成测试点 $test_num：小规模，包含负值"
cat > test_cases/test$test_num.in << EOF
3 2
-1 3 -2
EOF
let test_num++

# 测试点 4：中等规模，单调递增
echo "生成测试点 $test_num：中等规模，单调递增"
cat > test_cases/test$test_num.in << EOF
50000 4999
EOF
for ((i=1; i<=50000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done

let test_num++

# 测试点 5：中等规模，包含一些波动
echo "生成测试点 $test_num：中等规模，包含一些波动"
cat > test_cases/test$test_num.in << EOF
70000 50000
EOF
for ((i=1; i<=70000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done

let test_num++

# 测试点 6：大规模，随机分布
echo "生成测试点 $test_num：大规模，随机分布"
cat > test_cases/test$test_num.in << EOF
60000 50000
EOF
for ((i=1; i<=60000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done

let test_num++

# 测试点 7：最大坐标差
echo "生成测试点 $test_num：最大坐标差"
cat > test_cases/test$test_num.in << EOF
60000 50000
EOF
for ((i=1; i<=60000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done

let test_num++

# 测试点 8：高度相差小
echo "生成测试点 $test_num：高度相差小"
cat > test_cases/test$test_num.in << EOF
90000 50000
EOF
for ((i=1; i<=90000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done
let test_num++

# 测试点 9：非常大的数据
echo "生成测试点 $test_num：非常大的数据"
cat > test_cases/test$test_num.in << EOF
80000 50000
EOF
for ((i=1; i<=80000; i++)); do
    echo -n "$((RANDOM % 100000)) " >> test_cases/test$test_num.in
done
let test_num++

# 测试点 10：包含100000个怪物，值随机
echo "生成测试点 $test_num：包含100000个怪物，值随机"
cat > test_cases/test$test_num.in << EOF
100000 60000
EOF
for ((i=1; i<=100000; i++)); do
    echo -n "$((RANDOM % 10000)) " >> test_cases/test$test_num.in
done
let test_num++

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
