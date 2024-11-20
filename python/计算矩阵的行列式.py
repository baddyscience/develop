import numpy as np
try:
    a = np.array(eval(input())) 
    print(round(np.linalg.det(a),2))
except:
    print("输入错误！")