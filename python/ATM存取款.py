money = 1000
a = int(input())

if a == 1:
    b = float(input())
    if not b.is_integer() or b % 100 != 0:
        print("Incorrect Amount")
    elif b <= money:
        print(f"Balance:{int(money-b)}")
    else:
        print("Insufficient Funds")
elif a == 2:
    b = float(input())
    if not b.is_integer() or b % 100 != 0:
        print("Incorrect Amount")
    else:
        print(f"Balance:{int(money+b)}")
else:
    print("Wrong Option")