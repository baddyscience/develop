def solution(s: str) -> int:
    circle_count = {
        '0': 1,
        '1': 0,
        '2': 0,
        '3': 0,
        '4': 0,
        '5': 0,
        '6': 1,
        '7': 0,
        '8': 2,
        '9': 1
    }
    
    total_circles = 0
    
    for char in s:
        total_circles += circle_count[char]
    
    return total_circles

if __name__ == '__main__':
    print(solution(s = "1234567890") == 5)
    print(solution(s = "8690") == 5)
    print(solution(s = "1111") == 0)