def solution(array):
    candidate = None
    count = 0
    
    for num in array:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1
    
    return candidate

if __name__ == "__main__":
    print(solution([1, 3, 8, 2, 3, 1, 3, 3, 3]) == 3)
    print(solution([5, 5, 5, 1, 2, 5, 5]) == 5)
    print(solution([9, 9, 9, 9, 8, 9, 8, 8]) == 9)