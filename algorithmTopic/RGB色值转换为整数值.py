def solution(rgb):
    rgb_values = rgb[4:-1].split(', ')
    r, g, b = map(int, rgb_values)
    
    return (r << 16) + (g << 8) + b

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("rgb(192, 192, 192)") == 12632256 )
    print(solution("rgb(100, 0, 252)") == 6553852)
    print(solution("rgb(33, 44, 55)") == 2174007)