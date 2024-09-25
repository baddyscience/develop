ls = list(map(int, input().split()))
n = int(input())

if n in ls:
    ls = [x for x in ls if x != n]
    print(ls)
else:
    print("NOT FOUND")