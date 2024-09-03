#日期格式化输出
year = int(input())
month = int(input())
date = int(input())

print(f"{year} {month:02d} {date:02d}")
print(f"{year}-{month:02d}-{date:02d}")
print(f"{year}/{month:02d}/{date:02d}")
print(f"{month:02d},{date:02d},{year}")
print(f"{year}年{month:02d}月{date:02d}日")
print(str(year) + "年" + str(month).zfill(2) + "月" + str(date).zfill(2) + "日")
