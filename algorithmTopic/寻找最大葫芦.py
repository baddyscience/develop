def solution(n, max_value, array):
    from collections import Counter

    count = Counter(array)

    three_count_numbers = [num for num, cnt in count.items() if cnt >= 3]
    two_count_numbers = [num for num, cnt in count.items() if cnt >= 2]

    max_combination = [0, 0]

    for three_num in three_count_numbers:
        for two_num in two_count_numbers:
            if three_num == two_num and count[two_num] < 5:
                continue
            total = three_num * 3 + two_num * 2
            
            comp_three_num = 14 if three_num == 1 else three_num
            comp_two_num = 14 if two_num == 1 else two_num
            
            if total <= max_value:
                if (comp_three_num, comp_two_num) > tuple(max_combination):
                    max_combination = [comp_three_num, comp_two_num]

    if max_combination[0] == 14:
        max_combination[0] = 1
    if max_combination[1] == 14:
        max_combination[1] = 1

    return max_combination


if __name__ == "__main__":
    # Add your test cases here

    print(solution(9, 34, [6, 6, 6, 8, 8, 8, 5, 5, 1]) == [8, 5])
    print(solution(9, 37, [9, 9, 9, 9, 6, 6, 6, 6, 13]) == [6, 9])
    print(solution(9, 40, [1, 11, 13, 12, 7, 8, 11, 5, 6]) == [0, 0])
