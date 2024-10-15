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
a
EOF
cat > test_cases/test$test_num.ans << EOF
.
..
..a
EOF
let test_num++

# 测试点 2：包含所有元音字母
echo "生成测试点 $test_num：包含所有元音字母"
cat > test_cases/test$test_num.in << EOF
aeiouAEIOU
EOF
cat > test_cases/test$test_num.ans << EOF
..........
aei........
aeiouAEIOU
EOF
let test_num++

# 测试点 3：含有特殊字符（空格，标点符号）
echo "生成测试点 $test_num：含有特殊字符"
cat > test_cases/test$test_num.in << EOF
A quick-brown!fox,jumped over.
EOF
cat > test_cases/test$test_num.ans << EOF
. .....-.....!... ..... .....
A quick-b....!... ..... .....
A quick-brown!f.....over .....
EOF
let test_num++

# 测试点 4：仅包含特殊字符
echo "生成测试点 $test_num：仅包含特殊字符"
cat > test_cases/test$test_num.in << EOF
!.,:-;? 
EOF
cat > test_cases/test$test_num.ans << EOF
!.,:-;? 
!.,:-;? 
!.,:-;? 
EOF
let test_num++

# 测试点 5：最大长度字符（50 个字符）
echo "生成测试点 $test_num：最大长度字符"
cat > test_cases/test$test_num.in << EOF
MissionCriticalData! RetrieveImmediately#2024.
EOF
cat > test_cases/test$test_num.ans << EOF
......................! ..................#....
MissionCriticalDa! ......... ..................
MissionCriticalData! Ret..... ................. 
EOF
let test_num++

# 测试点 6：仅大写字母
echo "生成测试点 $test_num：仅大写字母"
cat > test_cases/test$test_num.in << EOF
HELLOWORLD
EOF
cat > test_cases/test$test_num.ans << EOF
..........
HEL.......
HELLO.....
EOF
let test_num++

# 测试点 7：字母、标点符号和空格
echo "生成测试点 $test_num：字母、标点符号和空格"
cat > test_cases/test$test_num.in << EOF
Save the data immediately!
EOF
cat > test_cases/test$test_num.ans << EOF
.... ... .... ..............!
Save the da... ..............!
Save the data immediat.ly!
EOF
let test_num++

# 测试点 8：小写字母和特殊字符
echo "生成测试点 $test_num：小写字母和特殊字符"
cat > test_cases/test$test_num.in << EOF
abcdef ghijklmnopqrstuvwxyz!
EOF
cat > test_cases/test$test_num.ans << EOF
...... .................!
abcde... .................!
abcdef ghi...lmno.....yz!
EOF
let test_num++

# 测试点 9：重复的相同字符
echo "生成测试点 $test_num：重复的相同字符"
cat > test_cases/test$test_num.in << EOF
aaaaaaaaaaaaaaaaaaaaaaaaaa
EOF
cat > test_cases/test$test_num.ans << EOF
..........................
aaaaaaaa......... ........
aaaaaaaaaaaaaaaaaa........
EOF
let test_num++

# 测试点 10：复杂字符组合
echo "生成测试点 $test_num：复杂字符组合"
cat > test_cases/test$test_num.in << EOF
ABab12#%% CdEfG-- !? HIJKL
EOF
cat > test_cases/test$test_num.ans << EOF
....12#%% ......-- !? .....
ABab12#%% Cd...-- !? .....
ABab12#%% CdEfG-- !? H.....
EOF
let test_num++

echo "测试点生成完毕！共生成 $test_num 个测试点，存放在 test_cases/ 目录下。"
