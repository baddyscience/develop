def solution(numbers):
    n = len(numbers)
    dp = [[0, 0] for _ in range(n + 1)]
    
    dp[0][0] = 1 
    dp[0][1] = 0 

    for i in range(1, n + 1):
        even_count = 0
        odd_count = 0
        
        odd_count = sum(1 for digit in str(numbers[i - 1]) if int(digit) % 2 != 0)
        even_count = sum(1 for digit in str(numbers[i - 1]) if int(digit) % 2 == 0)
        
        dp[i][0] = dp[i - 1][0] * even_count + dp[i - 1][1] * odd_count
        dp[i][1] = dp[i - 1][0] * odd_count + dp[i - 1][1] * even_count

    return dp[n][0]

if __name__ == "__main__":
    print(solution([123, 456, 789]) == 14)
    print(solution([123456789]) == 4)
    print(solution([14329, 7568]) == 10)
