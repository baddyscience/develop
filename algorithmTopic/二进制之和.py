def binary_sum(binary1, binary2):
    decimal1 = int(binary1, 2)
    decimal2 = int(binary2, 2)
    
    total = decimal1 + decimal2
    
    return str(total)

# 测试样例
print(binary_sum("101", "110"))  # 输出: '11'
print(binary_sum("111111", "10100"))  # 输出: '83'
print(binary_sum("111010101001001011", "100010101001"))  # 输出: '242420'
print(binary_sum("111010101001011", "10010101001"))  # 输出: '31220'
print(binary_sum("11", "1"))  # 输出: '4'
