from itertools import combinations
from collections import Counter

def find_original_numbers(n, sums):
    sums.sort()
    
    if n == 1:
        return "0" if sums[0] == 0 else "Impossible"
    
    total_sums = len(sums)

    for i in range(total_sums):
        for j in range(i + 1, total_sums):
            for k in range(j + 1, total_sums):
                a1_plus_a2 = sums[i]
                a1_plus_a3 = sums[j]
                a2_plus_a3 = sums[k]

                a1 = (a1_plus_a2 + a1_plus_a3 - a2_plus_a3) // 2
                a2 = a1_plus_a2 - a1
                a3 = a1_plus_a3 - a1

                original_numbers = [a1, a2, a3]

                remaining_sums = sums.copy()
                remaining_sums.remove(a1_plus_a2)
                remaining_sums.remove(a1_plus_a3)
                remaining_sums.remove(a2_plus_a3)

                for _ in range(3, n):
                    if remaining_sums:
                        next_number = remaining_sums[0] - a1
                        original_numbers.append(next_number)
                        remaining_sums.pop(0)

                calculated_sums = [a + b for a, b in combinations(original_numbers, 2)]
                
                if Counter(calculated_sums) == Counter(sums):
                    return ' '.join(map(str, sorted(original_numbers)))

    return "Impossible"

if __name__ == "__main__":
    # 测试用例
    print(find_original_numbers(3, [1269, 1160, 1663]))  # 期望: "383 777 886"
    print(find_original_numbers(3, [1, 1, 1]))          # 期望: "Impossible"
    print(find_original_numbers(5, [226, 223, 225, 224, 227, 229, 228, 226, 225, 227]))  # 期望: "111 112 113 114 115"
    print(find_original_numbers(5, [-1, 0, -1, -2, 1, 0, -1, 1, 0, -1]))  # 期望: "-1 -1 0 0 1"
    print(find_original_numbers(5, [79950, 79936, 79942, 79962, 79954, 79972, 79960, 79968, 79924, 79932]))  # 期望: "39953 39971 39979 39983 39989"
