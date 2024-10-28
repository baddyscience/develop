def solution(s):
    str="chhc"
    total_count = 0
    target_length = len(str)
    n = len(s)
    
    for i in range(n):
        for j in range(i + 1, n + 1):
            substring = s[i:j]
            count = 0
            start = 0
            
            while True:
                start = substring.find(str, start)
                if start == -1:
                    break
                count += 1
                start += 1
            
            total_count += count
    
    return total_count


if __name__ == '__main__':
    print(solution("chhchhc") == 8)
    print(solution("chhcchhcchhc") == 43)
    print(solution("hhhh") == 0)