def solution(n, array):
    # 初始化 L 和 R 数组
    L = [0] * n
    R = [0] * n
    
    # 使用栈来计算 L(i)
    stack = []
    for i in range(n):
        while stack and array[stack[-1]] <= array[i]:
            stack.pop()
        if stack:
            L[i] = stack[-1] + 1  # 因为题目要求的是 1-based index
        stack.append(i)
    
    # 使用栈来计算 R(i)
    stack = []
    for i in range(n-1, -1, -1):
        while stack and array[stack[-1]] <= array[i]:
            stack.pop()
        if stack:
            R[i] = stack[-1] + 1  # 因为题目要求的是 1-based index
        stack.append(i)
    
    # 计算 MAX(i) 并找到最大值
    max_value = 0
    for i in range(n):
        max_value = max(max_value, L[i] * R[i])
    
    return max_value

if __name__ == "__main__":
    # Add your test cases here
    print(solution(5, [5, 4, 3, 4, 5]) == 8)