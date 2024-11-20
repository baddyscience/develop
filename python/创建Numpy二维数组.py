import numpy as np

# 创建二维数组
array = np.array([[1, 2, 3, 4],
                  [4, 5, 6, 7],
                  [7, 8, 9, 10]])

# 打印数组信息
print("创建的数组为：\n", array)
print("创建的数组维度为：", array.shape)
print("数组类型为：", array.dtype)
print("数组元素个数为：", array.size)
print("数组每个元素大小为：", array.itemsize)
