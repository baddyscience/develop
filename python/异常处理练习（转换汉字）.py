import re

digit_to_chinese = ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九']

while True:
    user_input = input()

    if re.match(r"^-?\d+\.\d+$", user_input):
        print("输入类型错误，请输入整数")
        break
    elif re.match(r"^-?\d+$", user_input):
        try:
            digit = int(user_input)

            if digit:
                print(digit_to_chinese[digit])
                break
        except ValueError:
            print("输入错误，请重新输入")
            break
        except IndexError:
            print("输入超出范围")
            break
    else:
        print("输入错误，请重新输入")
        break
