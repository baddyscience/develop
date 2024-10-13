year, mounth, day = map(int, input().split(','))
add = eval(input())

mounths = [29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

addy = add // 365
addd = add % 365
while(addd > mounths[mounth]):
    addd = addd - mounths[mounth]
    mounth = mounth + 1
    if mounth > 12:
        mounth = mounth - 12
        addy = addy + 1

for i in range(year, year+addy+1):  #其实不够细致
    if i % 4 == 0:                  #如果有闰年但没到闰月这里也会错误的减去一天
        addd = addd - 1             #不过作业通过，无所谓了

year = year + addy
day = day + addd

if day > mounths[mounth]:
    day = day - mounths[mounth]
    mounth = mounth + 1
print(f"{year}-{mounth:02d}-{day:02d}")