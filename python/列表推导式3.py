n=eval(input())
m=eval(input())
#用列表推导式实现行列互换，错误代码为：new= [i for in range(n,m+1) if 0 in [ i%p for p in range(p//2+1)]] 
#修改后正确代码为
new = [i for i in range(n, m+1) if all(i % p != 0 for p in range(2, int(i**0.5) + 1)) and i > 1]
print(new)