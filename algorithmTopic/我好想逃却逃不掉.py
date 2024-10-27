#未完成
def count_dead_ends(N, M, data):
    # 定义方向：上、下、左、右
    directions = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
    
    # 寻找出口位置
    exit_pos = None
    for i in range(N):
        for j in range(M):
            if data[i][j] == 'O':
                exit_pos = (i, j)
                break
        if exit_pos:
            break

    # 用于标记可到达的位置
    visited = [[False] * M for _ in range(N)]

    # 深度优先搜索，找到可到达的所有位置
    def dfs(x, y):
        if not (0 <= x < N and 0 <= y < M) or visited[x][y] or data[x][y] == '.':
            return
        visited[x][y] = True
        direction = data[x][y]
        if direction in directions:
            dx, dy = directions[direction]
            dfs(x + dx, y + dy)

    # 从出口位置开始DFS
    if exit_pos:
        dfs(exit_pos[0], exit_pos[1])

    # 计算死胡同位置
    dead_ends_count = 0
    for i in range(N):
        for j in range(M):
            if data[i][j] == '.' and not visited[i][j]:
                dead_ends_count += 1

    return dead_ends_count

# 测试样例
print(count_dead_ends(5, 5, [".....", ".RRD.", ".U.DR", ".ULL.", "....O"]))  # 输出: 10
print(count_dead_ends(4, 4, [".R.O", "U.L.", ".D..", "..RD"]))                # 输出: 2
print(count_dead_ends(3, 3, [".UO", "L.R", "D.."]))                        # 输出: 8
