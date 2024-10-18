import numpy as np
import cv2  # 用于读取和显示图像
import filter  # 导入 C++ 扩展模块
import sys

# 添加生成的模块路径
sys.path.append("D:/Documents/Projects/VSCode Projects/Python/2024_10/MedianFilter/build/Debug")


# 读取图像
img = cv2.imread('./images/mlynar.jpg', cv2.IMREAD_COLOR)

# 将图像转换为 numpy 数组
img_np = np.array(img, dtype=np.uint8)

# 调用 C++ 中的中值滤波函数
filtered_img = filter.median_filter(img_np, 9)

# 调整图像大小
scale_percent = 50  # 图像缩小到原来的50%
width = int(filtered_img.shape[1] * scale_percent / 100)
height = int(filtered_img.shape[0] * scale_percent / 100)
dim = (width, height)


#保存图片
cv2.imwrite('images/filtered_img.jpg', filtered_img)

# 调整图像大小
resized_img = cv2.resize(filtered_img, dim, interpolation=cv2.INTER_AREA)

# 显示滤波后的图像
cv2.imshow('Filtered Image', resized_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
