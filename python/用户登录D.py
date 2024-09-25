dic = {'admin':'123456','administrator':'12345678','root':'password'}
max = 3

while max > 0:
    username = input()
    password = input()

    if username in dic and dic[username] == password:
        print("登录成功")
        break
    else:
        max -= 1
        print("登录失败")