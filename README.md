# 中值滤波器
## 简述
图片由python调用opencv读取，再转换成numpy矩阵

转换后的数组通过C++编写的滤波函数处理后再以图片的形式保持输出

连接C++和python用pybind11库实现

## 原理
通过卷积操作对图片的每一个像素进行处理

从而使图像中的噪音得到减轻
