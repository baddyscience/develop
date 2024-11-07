def solution(version1, version2):
    v1_parts = version1.split('.')
    v2_parts = version2.split('.')
    
    max_length = max(len(v1_parts), len(v2_parts))
    
    for i in range(max_length):
        v1_part = int(v1_parts[i]) if i < len(v1_parts) else 0
        v2_part = int(v2_parts[i]) if i < len(v2_parts) else 0
        
        if v1_part > v2_part:
            return 1
        elif v1_part < v2_part:
            return -1

    return 0

if __name__ == "__main__":
    # Add your test cases here
    print(solution("0.1", "1.1") == -1)
    print(solution("1.0.1", "1") == 1)
    print(solution("7.5.2.4", "7.5.3") == -1)
    print(solution("1.0", "1.0.0") == 0)