data = list(map(float, input().split()))
a, b, c, d = data
c = int(c)

if c == 1:
    an = ((d / a) / b)
elif c == 2:
    an = ((d / a) / (b / 12))
elif c == 3:
    an = ((d / a) / (b / 365))

print(f"在投资金额为:{a},投资时长为{b},收益为:{d}的情况下,年化收益率为:{an:.3f}")