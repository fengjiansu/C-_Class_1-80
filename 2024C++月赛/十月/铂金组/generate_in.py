import random
import os

# 获取当前 Python 文件所在目录
base_dir = os.path.dirname(os.path.abspath(__file__))

# 创建测试用例目录
test_cases_dir = os.path.join(base_dir, 'test_cases')
os.makedirs(test_cases_dir, exist_ok=True)

def generate_test_case(filename, n, q, max_value=1000000000):
    with open(filename, 'w') as f:
        f.write(f"{n} {q}\n")
        # 生成初始亮度值
        values = [random.randint(1, max_value) for _ in range(n)]
        f.write(' '.join(map(str, values)) + '\n')
        
        # 生成 q 个操作
        for _ in range(q):
            operation_type = random.choice([1, 2])
            if operation_type == 1:
                l = random.randint(1, n)
                r = random.randint(l, n)
                d = random.randint(-1000, 1000)
                f.write(f"1 {l} {r} {d}\n")
            else:
                l = random.randint(1, n)
                r = random.randint(l, n)
                f.write(f"2 {l} {r}\n")

# 随机生成测试用例
num_cases = 10
for i in range(num_cases):
    # 在指定范围内随机生成路灯数量和操作次数
    n = random.randint(1, 1000000)  # 随机路灯数量范围 [1, 1000000]
    q = random.randint(1, 1000000)   # 随机操作次数范围 [1, 1000000]
    
    input_file = os.path.join(test_cases_dir, f'test{i + 1}.in')
    generate_test_case(input_file, n, q)  # 生成自定义的测试用例

print(f"Test cases generated in: {test_cases_dir}")
