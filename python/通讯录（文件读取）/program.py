import csv
def read_csv_to_dict(file_path):
    data_dict={}
    with open(file_path,mode="r",encoding="GBK") as file:
        reader=csv.reader(file)
        for row in reader:
            name,phone,category=row[0],row[1],row[2]
            data_dict[name]=[phone,category]
    return data_dict

def output_as_rows(data_dict):
    for name,values in data_dict.items():
        print(name,values[0],values[1])

def main():
    file_path = r"info.csv"  # 设置文件路径
    try:
        data_dict = read_csv_to_dict(file_path)
    except FileNotFoundError:
        print("ERROR: 文件未找到，请检查路径是否正确。")
        return
    except Exception as e:
        print(f"ERROR: 文件读取失败，错误信息：{e}")
        return

    user_input = input().strip().upper()
    if user_input == 'A':
        output_as_rows(data_dict)
    elif user_input == 'D':
        print(data_dict)
    else:
        print("ERROR")

if __name__=="__main__":
    main()