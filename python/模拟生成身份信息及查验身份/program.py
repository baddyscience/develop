# 通过查验居民身份证可以掌握持证人的姓名、性别、出生日期、住址和公民身份证号码等信息，还可以获得居住后和出生地信息。
# 疫情期间，需要通过查验身份证来实现对一些出生或居住在敏感地区的人进行监控，现在需要你开发这样一个系统，具有以下功能：
# 1.为测试以上功能，模拟产生一个身份证上的全部信息。具体方法为
# 1.1 模拟姓名，从百家姓中抽取一个姓，注意百家姓文件中前51行为单姓，51行后面为双字复姓。根据性别从男或女性常用名中取机抽取一个名字。
# 1.2 模拟出生日期（限制1900-2020），性别随机男女、民族从56个民族中随机取一个
# 1.3 模拟住址，省、市、县区随机，随机一个小区、100以内整数楼号、房间号格式为 a - b0c,a 为 1-8， b为 0-35，c 为 1-4
# 1.4  模拟生成身份证号，出生序号随机。
# 1.5 按身份证格式打印输出模拟产生的身份证
# 2.输出年龄和性别
# 3.获取和输出身份证注册地的省、市、县（区）
# 4.获取持证人居住地的省、市、县（区）
# 5.根据输入设置敏感地区，判定持证人是否为敏感地区常住人或是敏感地区出生者。

import random
import datetime


def person_name(gender_of_id, last_name_file, male_name_file, female_name_file):
    """
    @参数 gender_of_id：性别，字符串类型
    @参数 last_name_file：百家姓文件名，字符串类型
    @参数 male_name_file：男性常用名文件名，字符串类型
    @参数 female_name_file：女性常用名文件名，字符串类型
    接收性别、百家姓文件名、男性常用名文件名、女性常用名文件名为参数
    先随机抽取一个姓氏，再根据性别随机抽取名字，
    返回表示姓名的字符串。
    """
点击在此输入一行或多行代码



def area_code(area_file):
    """
    @参数 area_file：包含地区编码的文件名，字符串类型
    传入参数为包含地区编码和地区名的文件名的字符串，以地区编码为键，地区名为值构建字典作为返回值。
    """
点击在此输入一行或多行代码



def birthdate():
    """在1900-2020间随机抽取一个数字作为出生年份，再随机生成一个合法的包含月和日的日期。需
    要注意月份范围为1-12，1、3、5、7、8、10、12月的日期范围为1-31，4、6、9、11的日期范围为1-30，闰年2月
    的日期范围为1-29，平年2月的日期范围为1-28。年为4位字符串，月和日均为2位字符串，依序构成长
    度为8的字符串作为返回值，例如19840509 """
    # year_of_birth = random.choice(range(1900, 2020))
    # days_of_rand = datetime.timedelta(days=random.randint(1, 366))
    # date_of_birth = datetime.date.today() + days_of_rand         # 月份和日期项
    # return str(year_of_birth) + date_of_birth.strftime('%m%d')   # 19840509
    year_of_birth = random.choice(range(1900, 2020))
    days_of_rand = datetime.timedelta(days=random.randint(1, 366))
    date_of_birth = datetime.datetime.strptime(str(year_of_birth)+'0101', "%Y%m%d") + days_of_rand          # 月份和日期项
    return date_of_birth.strftime("%Y%m%d")  # 19840509


def order_number(gender_of_id):
    """接收表示性别的字符串为参数，随机抽取1-99之间的整数作为生出顺序号，根据传入的性别随
    机抽取第17位序号数字，男性为偶数，女性为奇数。
    返回值为2位的顺序号，字符串类型
    """
    num = random.choice(range(1, 100))
    # gender_num = random.choice('13579') if gender_of_id == '男' else random.choice('02468')
    if gender_of_id == '男':
        gender_num = random.choice('13579')
    else:
        gender_num = random.choice('02468')

    return '{:02}'.format(num) + str(gender_num)


def id_of_17(area_of_code, birth_date, birth_order):
    """
    @参数 area_of_code：地区码字典
    @参数 birth_date：字符串
    @参数 birth_order：字符串
    接收地区码字典，出生日期和出生顺序号，随机抽取一个地区码，返回身份证号前17位的字符串。
    需要注意的是，抽取地区码时，要避免抽取到省或地级市的编码(最后2位编码为0)。
    """
点击在此输入一行或多行代码



def id17_to_18(id_number):
    """
    @ 参数 id_number：身份证号前17位，字符串
    为身份证号增加校验位，接收身份证号码前17位，返回18位身份证号，校验码的计算方法为：
    1. 将前面的身份证号码17位数分别乘以不同的系数。第一位到第十七位的系数分别为:
       7、9、10、5、8、4、2、1、6、3、7、9、10、5、8、4、2 ;
    2. 将这17位数字和系数相乘的结果相加;
    3. 用加出来和除以11，看余数是多少;
    4. 余数只可能有0、1、2、3、4、5、6、7、8、9、10这11个数字。
       其分别对应的最后一位身份证的号码为1、0、X、9、8、7、6、5、4、3、2，其中的X是罗马数字10;
    5. 通过上面得知如果余数是2，就会在身份证的第18位数字上出现罗马数字的Ⅹ；如果余数是10，
       身份证的最后一位号码就是2。
       返回值为18位身份证号，字符串类型。
    """
点击在此输入一行或多行代码



def village_of_live(village_file, area_of_code):
    """
    @ 参数 village_file：包含常见小区名的文件名，字符串类型
    @ 参数 area_of_code：地区编码，字典类型
    从village_file中随机选择一个小区名，从area_of_code中随机选择一个地区编码，并从中获取省、市、
    县(区)名。楼栋号限制[1-30]中随机，单元号限制[1-7]中随机，楼层号限制[1-35]中随机，
    房间号限制[1-4]中随机。
    返回值为居住地址和地区编码，均为字符串类型。
    """
    with open(village_file, 'r', encoding='utf-8') as data:
        village_live = data.readline().split()
    village = random.choice(village_live)
    building = random.choice(range(1, 30))
    door = random.choice(range(1, 7))
    floor = random.choice(range(1, 35))
    room = random.choice(range(1, 4))
    area_id = random.choice([x for x in list(area_of_code.keys()) if x[-2:] != '00'])  # 避免抽到省市的编码
点击在此输入一行或多行代码



def all_of_nation(nation_file):
    """
    @参数 nation_file：文件名，字符串类型
    传入参数为包含民族的文件名，从中随机抽取一个民族为返回值。
    需要注意的是，返回值里不包含'族'字，例如抽取'蒙古族',返回值为'蒙古'。
    """
点击在此输入一行或多行代码



def print_id(full_name, gender_of_id, id_number, address, nation, birth_date):
    """
    @ 参数 full_name：姓名，字符串类型
    @ 参数 gender_of_id： 性别，字符串类型
    @ 参数 id_number：公民身份证号， 字符串类型
    @ 参数 address：住址， 字符串类型
    @ 参数 nation：民族， 字符串类型
    @ 参数 birth_date：出生年月日， 字符串类型
    按身份证正面的格式输出完整的身份信息，包括：
    姓名
    性别   民族
    出生年月日
    住址
    公民身份号码"""
    print('-------------------------------------------------')
    print()
    print(f'  姓  名  {full_name}')
    print(f'  性  别  {gender_of_id}   民族  {nation}')
    print(f'  出  生  {birth_date[:4]} 年 {int(birth_date[4:6])} 月 {int(birth_date[6:])} 日')
    print(f'  住  址  {address[0]}')
    print()
    print(f'  公民身份号码 {id_number}')
    print('-------------------------------------------------')


# 获取和输出身份证注册地的省、市、县（区）
def area_of_registration(id_number, area_of_code):
    """
    @参数 id_number：身份证号，字符串
    @参数 area_of_code：地区编码，字典
    接收身份证号和地区编码的字典为参数，返回持证人身份证注册地址的省市县(区)。
    省的编码末4位为0
    地级市(区)编码末2位为0
    需要注意的是，若持证人注册地为直辖市，则住址中无地级市，直接输出市和区，例如：北京市朝阳区
    其他地区格式例如：湖北省武汉市洪山区。
    """
点击在此输入一行或多行代码



def area_of_live(area_id, area_of_code):
    """
    @参数 area_id：居住地编码，字符串
    @参数 area_of_code：地区编码，字典
    接收居住地编码和地区编码字典为参数，返回持证人居住地址的省市县(区)
    需要注意的是，若持证人居住地为直辖市，则住址中无地级市，直接输出市和区，例如：北京市朝阳区
    其他地区格式例如：湖北省武汉市洪山区。
    """
点击在此输入一行或多行代码



# 查验城市的编码
def check_city_code(city_name, area_of_code):
    """接收一个表示城市名的字符串参数和地区编码，若城市名存在，返回值为该城市对应的地区编码，6位字符串。
    若城市名不存在，返回False。
    @参数 city_name：城市名，字符串
    @参数 area_of_code：地区编码，字典类型
    """
点击在此输入一行或多行代码



def check_city(id_number, city_name, city_code, area_live):
    """
    @ 参数 id_number：身份证号，字符串类型
    @ 参数 city_name：查验城市名，字符串类型
    @ 参数 city_code：城市编码，字符串类型
    @ 参数 area_live：居住地信息，字符串类型
    接收参数身份证号，查验城市名和城市编码，居住地信息，查验持证人是否与指定的城市相关
    若居住地与查验城市名相同，返回持证人居住于city_name市
    否则若出生地与查验城市相同，返回持证人出生于city_name市
    其他情况返回持证人与city_name无关联。以及持证人居住信息。
    返回值均为字符串类型。
    """
点击在此输入一行或多行代码



def age_of_id(id_number):
    """接收身份证号为参数，返回值为持证人年龄和性别。
    年龄的计算方式为当前年份减出生年份。
    @参数 id_number：身份证号，字符串类型。
    """
    current_year = datetime.datetime.now().year
    gender = '男' if id_number[16] in '13579' else '女'
    age = current_year - int(id_number[6:10])
    return gender, age


def judge(txt):
    """接收一个字符串为参数，如果参数值为“姓名”，输出当前模拟身证上的姓名；
    如果参数是身份证号，输出当前模拟的身份证号的号码。如果参数值是“住址”，输出当前身份证号上的住址。
    如果参数值为“性别”，输出当前模拟身证上的性别；
    如果参数值为“姓名”，输出当前模拟身证上的姓名；
    如果参数值为“住址”，输出当前模拟身证上的住址；
    如果参数值为“身份证”，按身份证格式输出当前模拟身证上的全部信息；
    如果参数值为“查询”，,要求用户输入一个要查询的人名，再输入一个单词做为匹配词，
    根据输入设置敏感地区，判定持证人是否为敏感地区常住人或是敏感地区出生者。。"""
    if txt == '姓名':
        print(person)
    elif txt == '性别':
        print(user_gender)
    elif txt == '身份证号':
        print(id18)
    elif txt == '住址':
        print(address_and_code[0])
    elif txt == '身份证':
        print_id(person, user_gender, id18, address_and_code, nationality, date)
    elif txt == '查询':
        city_name = input()  # 输入敏感城市名
        city_code = check_city_code(city_name, area_number)
        if city_code:
            print(check_city(id18, city_name, city_code, address_and_code[0]))
        else:
            print('城市输入错误，请输入包含"市"在内的城市名')
        print(area_of_live(address_and_code[1], area_number))
    else:
        print('输入错误')


if __name__ == '__main__':
    last_name_filename = 'family names.txt'    # 百家姓
    male_name_filename = 'popularNameM.txt'    # 男性名来源文件
    female_name_filename = 'popularNameF.txt'  # 女性名来源文件
    area_filename = 'IDcode.txt'               # 地区码
    village_filename = 'villageName.txt'       # 常用小区名
    nation_filename = 'nation.txt'             # 民族
    random.seed(int(input()))                       # 随机数种子，不用于自动评测时注释掉此行
    user_gender = random.choice('男女')               # 随机生成男或女
    person = person_name(user_gender, last_name_filename, male_name_filename, female_name_filename)  # 根据性别生成人名
    area_number = area_code(area_filename)       # 地区编码，字典类型
    date = birthdate()                           # 随机生日
    order = order_number(user_gender)                 # 随机出生序号
    id17 = id_of_17(area_number, date, order)    # 拼接身份证号前17位
    id18 = id17_to_18(id17)                      # 加校验码成18位身份证号
    address_and_code = village_of_live(village_filename, area_number)
    nationality = all_of_nation(nation_filename)
    text = input()
    judge(text)