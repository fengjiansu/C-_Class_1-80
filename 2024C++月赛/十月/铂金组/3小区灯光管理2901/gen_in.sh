#!/bin/bash


# 生成测试点 1: 最小输入规模
echo "生成测试点 1"
cat > test1.in << EOF
1 1
100
2 1 1
EOF

# 生成测试点 2: 单次调整和查询
echo "生成测试点 2"
cat > test2.in << EOF
5 2
10 20 30 40 50
1 2 4 5
2 1 5
EOF

# 生成测试点 3: 多次调整和查询
echo "生成测试点 3"
cat > test3.in << EOF
6 5
5 10 15 20 25 30
1 1 3 10
2 1 6
1 4 6 -5
2 1 3
2 4 6
EOF

# 生成测试点 4: 最大增量和减量
echo "生成测试点 4"
cat > test4.in << EOF
4 4
1000000000 1000000000 1000000000 1000000000
1 1 4 1000000
2 1 4
1 1 4 -1000000
2 1 4
EOF

# 生成测试点 5: 随机大规模数据
echo "生成测试点 5"

n=10000
q=10000

echo "$n $q" > test5.in

# 生成随机初始亮度数组
for ((i=1; i<=n; i++)); do
    echo $((RANDOM % 1000000000 + 1)) >> test5.in
done

# 生成随机操作
for ((i=1; i<=q; i++)); do
    t=$((RANDOM % 2 + 1))
    if [ $t -eq 1 ]; then
        l=$((RANDOM % n + 1))
        r=$((RANDOM % n + 1))
        if [ $l -gt $r ]; then
            temp=$l; l=$r; r=$temp
        fi
        d=$((RANDOM % 2000001 - 1000000))
        echo "1 $l $r $d" >> test5.in
    else
        l=$((RANDOM % n + 1))
        r=$((RANDOM % n + 1))
        if [ $l -gt $r ]; then
            temp=$l; l=$r; r=$temp
        fi
        echo "2 $l $r" >> test5.in
    fi
done

# 生成测试点 6: 所有操作都是查询
echo "生成测试点 6"
cat > test6.in << EOF
8 5
3 6 9 12 15 18 21 24
2 1 8
2 3 5
2 6 8
2 1 4
2 5 8
EOF

# 生成测试点 7: 所有操作都是调整
echo "生成测试点 7"
cat > test7.in << EOF
7 5
10 20 30 40 50 60 70
1 1 7 5
1 2 6 -10
1 3 5 15
1 4 4 -20
1 1 7 10
EOF

# 生成测试点 8: 交替调整和查询
echo "生成测试点 8"
cat > test8.in << EOF
9 9
5 10 15 20 25 30 35 40 45
1 1 9 5
2 1 9
1 2 8 -3
2 1 9
1 3 7 2
2 1 9
1 4 6 -4
2 1 9
2 5 5
EOF

# 生成测试点 9: 边界值测试
echo "生成测试点 9"
cat > test9.in << EOF
2 4
1 1000000000
1 1 1 1000000
2 1 1
1 2 2 -1000000
2 2 2
EOF

# 生成测试点 10: 重复同一区间的操作
echo "生成测试点 10"
cat > test10.in << EOF
5 6
10 20 30 40 50
1 2 4 5
2 2 4
1 2 4 -3
2 2 4
1 2 4 2
2 2 4
EOF

echo "所有测试点生成完毕！"
