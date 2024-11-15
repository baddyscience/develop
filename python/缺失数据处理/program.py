import csv

s = input()

filename = r'缺失数据处理\filldata.csv'

processed_data = []

with open(filename, newline='', encoding='gbk') as file:
    reader = csv.reader(file)
    
    for row in reader:
        row = [s if value == '' or value is None else value for value in row]
        processed_data.append(row)

print(processed_data)
