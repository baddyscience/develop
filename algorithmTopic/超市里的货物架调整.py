def solution(n: int, m: int, s: str, c: str) -> int:
    demand = {}
    for item in c:
        if item in demand:
            demand[item] += 1
        else:
            demand[item] = 1
    
    sorted_s = sorted(s, key=lambda x: demand.get(x, 0), reverse=True)
    
    sold = 0
    for item in sorted_s:
        if demand.get(item, 0) > 0:
            sold += 1
            demand[item] -= 1
    
    return sold

if __name__ == '__main__':
    print(solution(3, 4, "abc", "abcd") == 3)
    print(solution(4, 2, "abbc", "bb") == 2)
    print(solution(5, 4, "bcdea", "abcd") == 4)