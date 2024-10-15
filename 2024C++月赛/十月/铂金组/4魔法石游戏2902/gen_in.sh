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
1
1
1
1
EOF
let test_num++

# 测试点 2：小规模，有解情况
echo "生成测试点 $test_num：小规模，有解情况"
cat > test_cases/test$test_num.in << EOF
5
1 2 3 4 5
2
3
5
EOF
let test_num++

# 测试点 3：小规模，无解情况
echo "生成测试点 $test_num：小规模，无解情况"
cat > test_cases/test$test_num.in << EOF
5
2 4 6 8 10
3
1
3
5
EOF
let test_num++

# 测试点 4：中等规模，随机数据
echo "生成测试点 $test_num：中等规模，随机数据"
n=100
Q=100
echo "$n" > test_cases/test$test_num.in
# 生成不同的魔力值，保证各不相同
shuf -i 1-1000 -n $n | tr '\n' ' ' >> test_cases/test$test_num.in
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# 随机生成 m 值
for ((i=1; i<=Q; i++)); do
    echo $((RANDOM % 1000 + 1)) >> test_cases/test$test_num.in
done
let test_num++

# 测试点 5：大规模，有解和无解混合
echo "生成测试点 $test_num：大规模，有解和无解混合"
n=10000
Q=10000
echo "$n" > test_cases/test$test_num.in
# 生成不同的魔力值，保证各不相同
shuf -i 1-100000 -n $n | tr '\n' ' ' >> test_cases/test$test_num.in
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# 随机生成 m 值
for ((i=1; i<=Q; i++)); do
    if [ $((RANDOM % 2)) -eq 0 ]; then
        # 选择一个存在的魔力值
        m=$(shuf -n1 test_cases/test$test_num.in | awk '{if(NR==2) print $0}' | tr ' ' '\n' | shuf -n1)
    else
        # 随机生成一个较大的值，可能无解
        m=$((RANDOM % 100000 + 100000))
    fi
    echo "$m" >> test_cases/test$test_num.in
done
let test_num++

# 测试点 6：最大输入规模
echo "生成测试点 $test_num：最大输入规模"
n=100000
Q=100000
echo "$n" > test_cases/test$test_num.in
# 生成不同的魔力值，保证各不相同
seq 1 $n | shuf | tr '\n' ' ' >> test_cases/test$test_num.in
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# m 值为随机大数
for ((i=1; i<=Q; i++)); do
    m=$((RANDOM % 1000000000 + 1))
    echo "$m" >> test_cases/test$test_num.in
done
let test_num++

# 测试点 7：所有 m 都有解
echo "生成测试点 $test_num：所有 m 都有解"
n=5000
Q=5000
echo "$n" > test_cases/test$test_num.in
# 生成顺序的魔力值
seq 1 $n | tr '\n' ' ' >> test_cases/test$test_num.in
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# m 值都在魔力值范围内
for ((i=1; i<=Q; i++)); do
    m=$((RANDOM % n + 1))
    echo "$m" >> test_cases/test$test_num.in
done
let test_num++

# 测试点 8：所有 m 都无解
echo "生成测试点 $test_num：所有 m 都无解"
n=5000
Q=5000
echo "$n" > test_cases/test$test_num.in
# 生成奇数的魔力值
for ((i=1; i<=n; i++)); do
    echo -n "$((2 * i - 1)) " >> test_cases/test$test_num.in
done
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# m 值为偶数，确保无解
for ((i=1; i<=Q; i++)); do
    m=$((2 * (RANDOM % 10000)))
    echo "$m" >> test_cases/test$test_num.in
done
let test_num++

# 测试点 9：重复的 m 值
echo "生成测试点 $test_num：重复的 m 值"
n=10000
Q=10000
echo "$n" > test_cases/test$test_num.in
# 生成随机魔力值
shuf -i 1-1000000 -n $n | tr '\n' ' ' >> test_cases/test$test_num.in
echo "" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
# 所有 m 值相同
m_value=500
for ((i=1; i<=Q; i++)); do
    echo "$m_value" >> test_cases/test$test_num.in
done
let test_num++

# 测试点 10：边界值测试
echo "生成测试点 $test_num：边界值测试"
n=1
Q=1
echo "$n" > test_cases/test$test_num.in
echo "1000000000" >> test_cases/test$test_num.in
echo "$Q" >> test_cases/test$test_num.in
echo "1000000000" >> test_cases/test$test_num.in

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
