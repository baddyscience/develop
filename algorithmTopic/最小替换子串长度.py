def solution(input):
    n = len(input)
    target_freq = n // 4
    
    freq = {'A': 0, 'S': 0, 'D': 0, 'F': 0}
    for char in input:
        freq[char] += 1
    
    if all(freq[char] == target_freq for char in 'ASDF'):
        return 0
    
    left = 0
    right = 0
    min_length = n
    
    window_freq = {'A': 0, 'S': 0, 'D': 0, 'F': 0}
    
    while right < n:
        window_freq[input[right]] += 1
        right += 1
        
        while all(freq[char] - window_freq[char] <= target_freq for char in 'ASDF'):
            min_length = min(min_length, right - left)
            window_freq[input[left]] -= 1
            left += 1
    
    return min_length

if __name__ == "__main__":
    # 你可以添加更多测试用例
    print(solution("ADDF") == 1)
    print(solution("ASAFASAFADDD") == 3)