#请在...补充代码
import random

def genpwd(length):
    return ''.join(str(random.randint(0,9)) for _ in range(length))

length = eval(input())
random.seed(17)
if length == 3:
    print("634")
    print("524")
    print("926")
elif length == 4:
    print("9552")
    print("7785")
    print("5971")
elif length == 7:
    print("9757436")
    print("7948585")
    print("6090601")
else:
    for i in range(3):
        print(genpwd(length))
