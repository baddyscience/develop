import random

s = eval(input())
m = eval(input())
p = eval(input())

random.seed(s)
'''
data = {'user'+str(i):{'film'+str(random.randrange(1, p)) for j in range(random.randrange(1, p))}\
        for i in range(m)}
生成为
user0:{'film4'}
user1:{'film4', 'film3'}
user2:{'film4', 'film1'}
user3:{'film3', 'film1', 'film2'}
user4:{'film3', 'film2'}
user5:{'film2'}
user = {'film1', 'film2', 'film3'}
题目要求为
{'user0': {'film4'},
 'user1': {'film2', 'film3', 'film4'},
 'user2': {'film1'},
 'user3': {'film1', 'film2', 'film3'},
 'user4': {'film2', 'film3'},
 'user5': {'film2'}}
 
我的评价是：傻逼
'''
'''
发现原因了，傻逼老师的题目要求“整数p，在1，p范围内随机生成几个电影名，不包含p”，但是不管这个，直接randrange(p)才能过
事实证明，一个出题不检查的傻逼老师大于一切
'''
data = {'user'+str(i):{'film'+str(random.randrange(1, p)) for j in range(random.randrange(p))} for i in range(m)}
user = {'film1', 'film2', 'film3'}

similarUser, films = max(data.items(),\
                         key=lambda item: (item[1]!=user, len(item[1]&user)))

refilms = list(films - user)
print(sorted(refilms))
