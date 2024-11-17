while True:
    user_input = input()

    if user_input.replace('.', '', 1).isdigit() or (user_input.startswith('-') and user_input[1:].replace('.', '', 1).isdigit()):
        divisor = float(user_input)

        if divisor != 0:
            result = 100 / divisor
            print(result)
            break