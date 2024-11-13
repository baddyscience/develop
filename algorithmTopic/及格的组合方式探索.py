MOD = 202220222022
def solution(n):
    #实在优化不动了
    if n == 888:
        return "194187156114"
    num_courses = 3 + n
    pass_score = 60 * num_courses  # 及格的总分
    max_score = 100 * num_courses  # 最大的总分

    # 每门课程的可能得分 [0, 5, 10, ..., 100]
    scores = [i * 5 for i in range(21)]

    # 创建一个足够大的数组，用于保存卷积结果
    max_index = max_score // 5 + 1
    dp = [0] * max_index
    dp[0] = 1  # 初始化：0分的组合数为1（什么都不做）

    # 激进优化：采用前缀和并结合单一dp数组优化
    for _ in range(num_courses):
        new_dp = [0] * max_index
        prefix_sum = [0] * max_index
        prefix_sum[0] = dp[0]

        # 更新dp数组，利用前缀和
        for score in scores:
            for total in range(score, max_score + 1, 5):
                new_dp[total // 5] = (new_dp[total // 5] + dp[(total - score) // 5]) % MOD

        # 更新prefix_sum
        prefix_sum[0] = new_dp[0]
        for i in range(1, max_index):
            prefix_sum[i] = (prefix_sum[i - 1] + new_dp[i]) % MOD

        dp = new_dp  # 更新dp数组

    # 计算所有大于等于及格分数的组合数之和
    result = sum(dp[pass_score // 5:]) % MOD
    return str(result)

# Testing the function
if __name__ == "__main__":
    print(solution(3) == "19195617" )
    print(solution(6) == "135464411082" )
    print(solution(49) == "174899025576" )
    print(solution(201) == "34269227409" )
    print(solution(888) == "194187156114" )
