def solution(dna1, dna2):
    len1 = len(dna1)
    len2 = len(dna2)
    
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

    for i in range(len1 + 1):
        dp[i][0] = i 
    for j in range(len2 + 1):
        dp[0][j] = j

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if dna1[i - 1] == dna2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j] + 1,
                               dp[i][j - 1] + 1,
                               dp[i - 1][j - 1] + 1) 

    return dp[len1][len2]

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("AGCTTAGC", "AGCTAGCT") == 2 )
    print(solution("AGCCGAGC", "GCTAGCT") == 4)