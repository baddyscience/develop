def isp(num):
    if num < 2:
        return False
    for i in range(2, int(num / 2) + 1):
        if num % i == 0:
            return False
    return True

def ispt(x):
    return isp(x[1])

def getp(n):
    numbers = list(range(2, n))
    primes = filter(ispt, enumerate(numbers, 2))
    
    return [x[1] for x in primes]

num = int(input())

print(getp(num))