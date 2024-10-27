def solution(n, data):
    max_product = -1
    best_start, best_end = -1, -1
    
    for start in range(n):
        current_product = 1
        for end in range(start, n):
            current_product *= data[end]
            
            if current_product == 0:
                break
            
            if current_product > max_product:
                max_product = current_product
                best_start, best_end = start, end
            elif current_product == max_product:
                if start < best_start or (start == best_start and end < best_end):
                    best_start, best_end = start, end

    return [best_start + 1, best_end + 1]

if __name__ == "__main__":
    # Add your test cases here
    print(solution(5, [1, 2, 4, 0, 8]) == [1, 3])
    print(solution(7, [1, 2, 4, 8, 0, 256, 0]) == [6, 6])