user_data = {
    "aaa": "123456",
    "bbb": "888888",
    "ccc": "333333"
}

username = input()
password = input() 

if username not in user_data:
    print("Wrong User")
elif user_data[username] == password:
    print("Success")
else:
    print("Fail")