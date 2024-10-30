def say_hi_default(full_name, gender="男"):
    """定义一个名为say_hi_default的默认值函数
    根据性别gender值确定称谓，男性称为“先生”，女性称为“女士”，
    不确定性别时称为“先生/女士”。当函数调用时未给出gender时，默认按男性处理
    返回值为替换了姓名与称谓的欢迎字符串
    例如：尊敬的李白先生，欢迎来到火星！"""
    
    if gender == "男":
        title = "先生"
    elif gender == "女":
        title = "女士"
    else:
        title = "先生/女士"
    
    return f"尊敬的{full_name}{title}，欢迎来到火星！"

# 函数名作为print()函数的参数，输出say_hi_default()的返回值
person_info = input().split()  # 输入人名与性别，性别可省略
print(say_hi_default(*person_info))  # 输出欢迎信息
