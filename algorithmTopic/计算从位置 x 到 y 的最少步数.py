#未完成
def min_steps(x, y):
    # 确定目标方向
    distance = abs(y - x)
    steps = 0
    step_length = 1
    
    while distance > 0:
        steps += 1
        distance -= step_length
        step_length += 1  # 下一步可以增加步长

    # 如果还未到达目标，可能需要进行额外的调整
    if distance < 0 and (step_length - 1) % 2 != distance % 2:
        steps += 2  # 需要多走两步调整
    return steps

# 测试样例
if __name__ == "__main__":
    print(min_steps(12, 6))   # 输出: 4
    print(min_steps(34, 45))  # 输出: 6
    print(min_steps(50, 30))  # 输出: 8
    print(min_steps(0, 0))    # 输出: 0
