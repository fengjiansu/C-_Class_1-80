#!/bin/bash

# 检查 test_cases 目录是否存在
if [ -d "test_cases" ]; then
    echo "正在删除所有 .ans 文件..."
    
    # 删除 test_cases 目录下的所有 .ans 文件
    find test_cases -name "*.ans" -type f -delete
    
    echo "删除完成。"
else
    echo "目录 test_cases 不存在。"
fi
