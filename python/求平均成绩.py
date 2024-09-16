import sys
def ca(n, m, scores):
    scorces = [0] * n
    
    for score_list in scores:
        for i in range(n):
            scorces[i] += score_list[i]
    
    averages = [total / m for total in scorces]
    for average in averages:
        print(f"{average:.1f}")

input = sys.stdin.read
data = input().strip().split('\n')
    
n, m = map(int, data[0].split())
    
scores = [list(map(float, line.split())) for line in data[1:]]
    
ca(n, m, scores)