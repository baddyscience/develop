scores = {"Zhang San": 45, "Li Si": 78, "Wang Wu": 40,
            "Zhou Liu": 96,"Zhao Qi": 65, "Sun Ba": 90,
            "Zheng Jiu": 78, "Wu Shi": 99,"Dong Shiyi": 60}

max = 0
min = 10000
total = 0
top = []

for name, score in scores.items():
    if score > max:
        max = score
    if score < min:
        min = score
    total += score

av = total / len(scores)

for name, score in scores.items():
    if score == max:
        top.append(name)

print(f"最高分是:{max},最低分是{min},平均分是{av:.3f}")
print(f"最高分对应的学生是{top[0]}")