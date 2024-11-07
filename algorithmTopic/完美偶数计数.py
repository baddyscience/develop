def solution(n: int, l: int, r: int, a: list) -> int:
    count = 0
    
    for num in a:
        if num % 2 == 0 and l <= num <= r:
            count += 1
    
    return count

if __name__ == '__main__':
    print(solution(5, 3, 8, [1, 2, 6, 8, 7]) == 2)
    print(solution(4, 10, 20, [12, 15, 18, 9]) == 2)
    print(solution(3, 1, 10, [2, 4, 6]) == 3)