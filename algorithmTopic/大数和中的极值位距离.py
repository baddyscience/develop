def solution(string1, string2):
    total = str(int(string1) + int(string2))
    
    max_digit = max(total)
    min_digit = min(total)
    
    if max_digit == min_digit:
        return 0

    max_indices = [i for i, digit in enumerate(total) if digit == max_digit]
    min_indices = [i for i, digit in enumerate(total) if digit == min_digit]
    
    min_diff = min(abs(max_i - min_i) for max_i in max_indices for min_i in min_indices)
    
    return min_diff-1

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("111", "222") == 0 )
    print(solution("111", "34") == 1)
    print(solution("5976762424003073", "6301027308640389") == 6)