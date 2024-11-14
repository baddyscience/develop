import csv
import json

# 读取 CSV 文件并转换为字典
def read_csv_to_dict(file_path):
    contact_dict = {}
    with open(file_path, mode='r', encoding='GBK') as file:
        reader = csv.reader(file)
        for row in reader:
            if len(row) == 3:  # 确保每行有三个字段
                name, phone, department = row
                contact_dict[name] = [phone, department] 
    return contact_dict

# 打印字典格式化输出
def print_dict(contact_dict):
    print("{")
    for name, (phone, department) in contact_dict.items():
        # 按照需求的格式输出
        print(f"    '{name}': ['{phone}', '{department}'],")
    print("}")

# 打印 CSV 文件的内容
def print_csv(file_path):
    with open(file_path, mode='r', encoding='GBK') as file:
        reader = csv.reader(file)
        for row in reader:
            if len(row) == 3:
                print(' '.join(row))

# 主程序
def main():
    file_path = r'C:\Users\Museum\OneDrive\develop\python\通讯录（文件读取）\info.csv'  # 请根据实际文件路径修改
    contact_dict = read_csv_to_dict(file_path)
    
    while True:
        user_input = input().strip()
        
        if user_input == 'A':
            print_csv(file_path)
        elif user_input == 'D':
            print_dict(contact_dict)
        else:
            print("ERROR")

if __name__ == '__main__':
    main()
