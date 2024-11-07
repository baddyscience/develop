def solution(A):
    if A == 1:
        return 1
    if A == 2:
        return 2
    
    prev2 = 1
    prev1 = 1 
    current = 0
    
    for month in range(2, A + 1):
        current = prev1 + prev2 
        prev2 = prev1
        prev1 = current
    
    return current


if __name__ == "__main__":
    # Add your test cases here
    print(solution(5) == 8)
    print(solution(1) == 1)
    print(solution(15) == 987)
    print(solution(50) == 20365011074)
