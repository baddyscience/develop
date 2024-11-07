def solution(plates, n):
    result = []
    i = 0
    
    while i < len(plates):
        start = i
        while i + 1 < len(plates) and plates[i + 1] == plates[i] + 1:
            i += 1
        
        if i - start >= 2:
            result.append(f"{plates[start]}-{plates[i]}")
        else:
            for j in range(start, i + 1):
                result.append(str(plates[j]))
        
        i += 1
    
    return ",".join(result)

if __name__ == "__main__":
    print(solution([-3, -2, -1, 2, 10, 15, 16, 18, 19, 20], 10) == "-3--1,2,10,15,16,18-20")
    print(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20], 20) == "-6,-3-1,3-5,7-11,14,15,17-20")
    print(solution([1, 2, 7, 8, 9, 10, 11, 19], 8) == "1,2,7-11,19")