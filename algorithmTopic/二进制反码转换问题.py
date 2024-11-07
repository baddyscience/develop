def solution(N: int) -> int:
    binary_str = bin(N)[2:]
    
    inverted_binary_str = ''.join('1' if bit == '0' else '0' for bit in binary_str)
    
    result = int(inverted_binary_str, 2)
    
    return result

if __name__ == '__main__':
    print(solution(N=5) == 2)
    print(solution(N=10) == 5)
    print(solution(N=0) == 1)