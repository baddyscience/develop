
money = float(input())
months = int(input())
method = input()
rate = float(input())

if method == "ACPI":
    payment = money * rate * (1 + rate)**months / ((1 + rate)**months - 1)
    print(round(payment, 2))

elif method == "AC":
    payments = []
    for i in range(1, months + 1):
        payment = money / months + (money - (i - 1) * money / months) * rate
        payments.append(round(payment, 2))
    print(f"[{', '.join(map(str, payments))}]")

else:
    print("还款方式输入错误")
