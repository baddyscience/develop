def solution(n, m, array):
    # 初始化战力值限制数组
    max_arrays = [float('inf')] * n
    for idx, maxPower in array:
        max_arrays[idx] = maxPower
    
    # 从左到右推导最大可能的战力值
    power = [0] * n
    for i in range(1, n):
        power[i] = min(power[i - 1] + 1, max_arrays[i])
    
    # 从右到左调整
    for i in range(n - 2, -1, -1):
        power[i] = min(power[i], power[i + 1] + 1)
    
    # 返回所有角色中的最大战力值
    return max(power)

if __name__ == "__main__":
    # Add your test cases here

    print(solution(3, 2, [[1, 3], [2, 2]]) == 2)
    print(solution(5, 3, [[1, 1], [2, 3], [4, 3]]) == 3)
