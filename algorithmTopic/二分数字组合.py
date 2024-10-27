def solution(n, A, B, array_a):
    total_sum = sum(array_a)
    total_sum_mod = total_sum % 10
    
    if total_sum_mod == A or total_sum_mod == B:
        return 1
    
    memo = {}
    
    def backtrack(index, sum1, sum2):
        if index == n:
            return 1 if sum1 % 10 == A and sum2 % 10 == B else 0
        if (index, sum1 % 10, sum2 % 10) in memo:
            return memo[(index, sum1 % 10, sum2 % 10)]
        
        count1 = backtrack(index + 1, sum1 + array_a[index], sum2)
        count2 = backtrack(index + 1, sum1, sum2 + array_a[index])
        memo[(index, sum1 % 10, sum2 % 10)] = count1 + count2
        
        return memo[(index, sum1 % 10, sum2 % 10)]
    
    return backtrack(0, 0, 0)

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution(3, 1, 2, [1,1,1]) == 3 )
    print(solution(3, 3, 5, [1,1,1]) == 1 )
    print(solution(2, 1, 1, [1,1]) == 2 )