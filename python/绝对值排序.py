def sort(x):
    return (abs(x), x)

list1 = eval(input())

list = sorted(list1, key=sort, reverse =True)

print(','.join(map(str, list)))