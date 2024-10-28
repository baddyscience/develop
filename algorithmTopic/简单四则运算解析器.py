def solution(expression):
    def evaluate(ops, nums):
        right = nums.pop()
        left = nums.pop()
        op = ops.pop()
        if op == '+':
            nums.append(left + right)
        elif op == '-':
            nums.append(left - right)
        elif op == '*':
            nums.append(left * right)
        elif op == '/':
            nums.append(left // right) 

    def precedence(op):
        if op in ('+', '-'):
            return 1
        if op in ('*', '/'):
            return 2
        return 0

    ops = []
    nums = []
    i = 0

    while i < len(expression):
        if expression[i].isdigit():
            num = 0
            while i < len(expression) and expression[i].isdigit():
                num = num * 10 + int(expression[i])
                i += 1
            nums.append(num)
            continue
        elif expression[i] in "+-*/":
            while (ops and precedence(ops[-1]) >= precedence(expression[i])):
                evaluate(ops, nums)
            ops.append(expression[i])
        elif expression[i] == '(':
            ops.append(expression[i])
        elif expression[i] == ')':
            while ops and ops[-1] != '(':
                evaluate(ops, nums)
            ops.pop() 
        i += 1

    while ops:
        evaluate(ops, nums)

    return nums[0]

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("1+1") == 2)
    print(solution("3+4*5/(3+2)") == 7)
    print(solution("4+2*5-2/1") == 12)
    print(solution("(1+(4+5+2)-3)+(6+8)") == 23)