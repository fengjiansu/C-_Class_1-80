#!/bin/bash

# 编译解决方案代码
g++ -ID:\\C++_Code\\testlib 星际大战.cpp -o solution

# 遍历所有输入测试点
for i in {2..6}
do
    echo "Running test $i..."
    ./solution < test_cases/test$i.in > test_cases/test$i.out
    
    # 如果你有标准答案，可以直接 diff 检查
    # if diff -q test$i.out test$i.ans > /dev/null; then
    #     echo "Test $i passed!"
    # else
    #     echo "Test $i failed!"
    # fi
done
