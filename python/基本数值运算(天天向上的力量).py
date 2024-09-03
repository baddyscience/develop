import math
n = float(input())

up = math.pow(1 + n / 100, 365)
down = math.pow(1 - n / 100, 365)

print(f"天天努力的结果{up:.3f}，天天躺平的结果{down:.3f}")

