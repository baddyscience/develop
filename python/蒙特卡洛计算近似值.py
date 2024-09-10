import random
sd = int(input())
n = int(input())

random.seed(sd)
c = 0
for i in range(n):
    x, y = random.uniform(-1, 1), random.uniform(-1, 1)
    if x**2 + y**2 <= 1:
        c += 1
        
pi = 4 * c / n
print(f"{pi}")