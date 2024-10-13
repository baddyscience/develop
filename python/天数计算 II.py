x,y = eval(input())

mounth = [29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

if x % 4 == 0:
    if y == 2:
        print(f"{mounth[0]}")
    else:
        print(f"{mounth[y]}")
else:
    print(f"{mounth[y]}")