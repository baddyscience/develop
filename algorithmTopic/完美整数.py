def solution(x, y):
    count = 0
    for d in range(1, 10):
        num = d
        while num <= y:
            if num >= x:
                count += 1
            num = num * 10 + d 
    return count
if __name__ == "__main__":
    print(solution(1, 10) == 9)
    print(solution(2, 22) == 10)