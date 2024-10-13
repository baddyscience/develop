x = list(map(int, input().split(',')))
y = list(map(float, input().split(',')))

n = len(x)

sumx = sum(x)
sumy = sum(y)
sumx2 = sum([xi ** 2 for xi in x])
sumxy = sum([xi * yi for xi, yi in zip(x, y)])

b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx ** 2)
a = (sumy - b * sumx) / n

ynext = a+ b * (n+1)

print(f"{ynext:.1f}")
