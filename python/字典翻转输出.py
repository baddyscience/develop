a = eval(input())

try:
    if not isinstance(a, dict):
        raise ValueError

    dict = {v: k for k, v in a.items()}
    
    print(dict)

except (ValueError):
    print("输入错误")