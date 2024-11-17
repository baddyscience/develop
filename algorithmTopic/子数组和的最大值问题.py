def solution(n, k, nums):
    # 如果 n == k，直接返回数组的总和
    if n == k:
        return sum(nums)

    max_sum_after_removal = float('-inf')

    # 尝试删除每个元素
    for i in range(n):
        # 创建新数组（删除第 i 个元素）
        remaining_nums = nums[:i] + nums[i+1:]
        # 使用滑动窗口找到长度为 k 的最大子数组和
        window_sum = 0
        max_window_sum = float('-inf')
        
        for j in range(len(remaining_nums)):
            window_sum += remaining_nums[j]
            if j >= k - 1:
                max_window_sum = max(max_window_sum, window_sum)
                window_sum -= remaining_nums[j - (k - 1)]
        
        # 更新全局最大和
        max_sum_after_removal = max(max_sum_after_removal, max_window_sum)

    return max_sum_after_removal

# 测试用例
if __name__ == "__main__":
    print(solution(5, 3, [2, 1, 3, -1, 4]))  # 应输出 8
    print(solution(6, 2, [-1, -1, 5, -2, 3, 4]))  # 应输出 8
    print(solution(4, 2, [-5, -3, 2, 1]))  # 应输出 3
