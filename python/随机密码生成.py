#请在...补充代码
import random

def genpwd(length):
    a = pow(10,length-1)
    b = pow(10,length)-1
    return random.randint(a,b)

length = eval(input())
random.seed(17)

for i in range(3):
    print(genpwd(length))
