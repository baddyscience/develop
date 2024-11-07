def solution(m, n, target, array):
    INF = float('inf')
    
    diff_matrix = {
        'A': {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': INF},
        'B': {'A': 1, 'B': 0, 'C': 1, 'D': INF, 'E': INF},
        'C': {'A': 2, 'B': 1, 'C': 0, 'D': 1, 'E': INF},
        'D': {'A': 3, 'B': INF, 'C': 1, 'D': 0, 'E': 1},
        'E': {'A': INF, 'B': INF, 'C': INF, 'D': 1, 'E': 0}
    }
    
    def calculate_diff(password1, password2):
        total_diff = 0
        for i in range(m):
            char1 = password1[i]
            char2 = password2[i]
            if diff_matrix[char1][char2] == INF:
                return INF  
            total_diff += diff_matrix[char1][char2]
        return total_diff
    
    min_diff = INF
    best_candidates = []
    
    for candidate in array:
        diff = calculate_diff(target, candidate)
        if diff < min_diff:
            min_diff = diff
            best_candidates = [candidate]
        elif diff == min_diff:
            best_candidates.append(candidate)
    
    return ' '.join(best_candidates) if min_diff != INF else 'None'



if __name__ == "__main__":
    # Add your test cases here
    m = 6
    n = 3
    target = "ABCDEA"
    array = ["AAAAAA", "BBBBBB", "ABDDEB"]
    print(solution(m, n, target, array))
    m = 4
    n = 4
    target = "AEBC"
    array = ["ACDC", "BBDC", "EBCB", "BBBB"]
    print(solution(m, n, target, array))
    m = 5
    n = 15
    target = "ACABB"
    array = ["EAACE","AABCC","DCBCD","ECCAE","BBACD","DCCAB","BBDBD","BCAAD","EABAC","CBCDA","DBBAE","ABDBB","EDDAD","DBBAC","BDACC"]
    print(solution(m, n, target, array))
