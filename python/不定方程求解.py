a, b, c = map(int, input().split())

answer = []

for x in range(c // a + 1):
    r = c - a * x
    if r % b == 0:
        y = r // b
        if y >= 0:
            answer.append([x, y])

print(answer)

print(len(answer))