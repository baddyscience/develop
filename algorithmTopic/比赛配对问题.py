def solution(n: int) -> int:
    matches = 0
    
    while n > 1:
        if n % 2 == 0:
            matches += n // 2
            n //= 2
        else:
            matches += (n - 1) // 2
            # 剩余 (n - 1) / 2 + 1 支队伍
            n = (n - 1) // 2 + 1
    
    return matches

if __name__ == '__main__':
    print(solution(7) == 6)
    print(solution(14) == 13)
    print(solution(1) == 0)