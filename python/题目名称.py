n=eval(input())       
for i in range(n, 1, -1):
    for k in range(2, i):
        if i % k == 0:
            break
    else:
        print(i)
        break