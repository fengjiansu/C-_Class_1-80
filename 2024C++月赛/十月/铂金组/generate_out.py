import subprocess
import os

# 获取当前 Python 文件所在目录
base_dir = os.path.dirname(os.path.abspath(__file__))

# 获取测试用例目录
test_cases_dir = os.path.join(base_dir, 'test_cases')

# 打印路径以进行调试
print(f"Base directory: {base_dir}")
print(f"Test cases directory: {test_cases_dir}")

# 获取程序名（去掉 .cpp 后缀）
program_name = '1'  # 修改为你的程序名，不带 .cpp 后缀

# 编译 C++ 程序
subprocess.run(['g++', os.path.join(base_dir, f'{program_name}.cpp'), '-o', os.path.join(base_dir, program_name)])

# 遍历输入文件
for filename in os.listdir(test_cases_dir):
    if filename.endswith('.in'):
        input_file_path = os.path.join(test_cases_dir, filename)
        output_file_path = os.path.join(test_cases_dir, filename.replace('.in', '.out'))

        # 调用 C++ 程序，并将输入输出重定向
        with open(input_file_path, 'r') as input_file, open(output_file_path, 'w') as output_file:
            subprocess.run([os.path.join(base_dir, program_name)], stdin=input_file, stdout=output_file)

print("Processing completed.")
