import jieba
import wordcloud
from imageio import imread
import matplotlib.pyplot as plt

# 读取形状图像
mask = imread(r"C:\Users\Museum\OneDrive\develop\python\词云\2.jpg")

# 读取文本文件
with open(r"C:\Users\Museum\OneDrive\develop\python\词云\2020政府工作报告.txt", "r", encoding="utf-8") as f:
    t = f.read()

# 去除停用词
exwords = ['的', '和', '要']
for word in exwords:
    t = t.replace(word, '')

# 使用 jieba 进行分词
ls = jieba.lcut(t)
txt = " ".join(ls)

# 指定字体文件路径
font_path = r"C:\Users\Museum\OneDrive\develop\python\词云\GoNotoKurrent-Bold.ttf"

# 创建 WordCloud 对象，并指定字体文件路径和形状掩码
w = wordcloud.WordCloud(
    font_path=font_path,
    mask=mask,
    width=1000,
    height=700,
    background_color="white"
)

# 生成词云
w.generate(txt)

# 保存词云图
w.to_file("aixin.png")

# 显示词云图
plt.imshow(w, interpolation='bilinear')
plt.axis("off")
plt.show()
