# 小S正在玩一个关于石子的游戏，给定了一些石子，它们位于一维数轴的不同位置，位置用数组stones表示。如果某个石子处于最小或最大的一个位置，我们称其为端点石子。
# 在每个回合，小S可以将一颗端点石子移动到一个未占用的位置，使其不再是端点石子。游戏继续，直到石子的位置变得连续，无法再进行任何移动操作。
# 你需要帮助小S找到可以移动的最大次数。
def solution(stones: list) -> int:
    stones.sort()
    n = len(stones)
    
    if n <= 2:
        return 0
    max_moves = max(stones[-1] - stones[1], stones[-2] - stones[0]) - (n - 2)
    
    return max_moves

if __name__ == '__main__':
    print(solution(stones=[7, 4, 9]) == 2)
    print(solution(stones=[6, 5, 4, 3, 10]) == 3)
    print(solution(stones=[1, 2, 3, 4, 5]) == 0)