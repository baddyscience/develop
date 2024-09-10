last = []

for i in range(4):
    name = input()
    last.append(name[-1])

cname = ''.join(last)

print(f"我们宿舍的组合是：{cname}")
