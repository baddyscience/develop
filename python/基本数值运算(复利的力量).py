x=input()
#此行代码用来接收输入的一串字符，并按空格分割，然后用map函数转换为浮点数
#如果输入的是50 1，则a=50,n=1
a,n=map(float,x.split())

import math
x = a * math.pow(1 + n/100, 40)
print(f"本金{a}，利率为{n:.1f}%的情况下，40年后拥有的资产是{x:.3f}元")