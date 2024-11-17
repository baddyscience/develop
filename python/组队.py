def solution(n: int, k: int, a: list, b: list) -> int:
    # 计算所有可能的差别值的最大值
    max_difference = max(abs(a[i] - a[j]) + abs(b[i] - b[j]) for i in range(n) for j in range(n))
    
    # 二分查找 L 的最大值
    left, right = 0, max_difference
    while left < right:
        mid = (left + right + 1) // 2
        if can_form_groups(n, k, a, b, mid):
            left = mid
        else:
            right = mid - 1
    
    return left

def can_form_groups(n: int, k: int, a: list, b: list, L: int) -> bool:
    # 初始化并查集
    parent = list(range(n))
    rank = [1] * n
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        rootX = find(x)
        rootY = find(y)
        if rootX != rootY:
            if rank[rootX] > rank[rootY]:
                parent[rootY] = rootX
            elif rank[rootX] < rank[rootY]:
                parent[rootX] = rootY
            else:
                parent[rootY] = rootX
                rank[rootX] += 1
    
    # 合并差别值不超过 L 的人
    for i in range(n):
        for j in range(i + 1, n):
            if abs(a[i] - a[j]) + abs(b[i] - b[j]) <= L:
                union(i, j)
    
    # 统计组数
    groups = len(set(find(i) for i in range(n)))
    return groups >= k

if __name__ == '__main__':
    print(solution(3, 2, [1, 9, 3], [2, 7, 8]) == 7)
    print(solution(4, 3, [10, 20, 30, 40], [5, 15, 25, 35]) == 19)
    print(solution(5, 2, [100, 50, 25, 75, 10], [90, 45, 20, 80, 15]) == 59)