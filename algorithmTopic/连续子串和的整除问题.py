def solution(n, b, sequence):
    prefix_sum_mod = {0: 1}
    prefix_sum = 0
    count = 0

    for num in sequence:
        prefix_sum += num
        current_mod = prefix_sum % b

        if current_mod in prefix_sum_mod:
            count += prefix_sum_mod[current_mod]
            prefix_sum_mod[current_mod] += 1
        else:
            prefix_sum_mod[current_mod] = 1

    return count

if __name__ == "__main__":
    sequence = [1, 2, 3]
    print(solution(3, 3, sequence) == 3)