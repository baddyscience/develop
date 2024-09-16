def search(lst):
    lens = len(lst)

    maxs = lens
    
    for item in lst:
        if isinstance(item, list):
            maxs = max(maxs, search(item))
    
    return maxs

list1 = eval(input())

print(search(list1))
