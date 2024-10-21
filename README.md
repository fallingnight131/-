# 中值滤波器
## 简述
图片由python调用opencv读取，再转换成numpy矩阵

转换后的数组通过C++编写的滤波函数处理后再以图片的形式保持输出

连接C++和python用pybind11库实现

## 原理
通过卷积操作对图片的每一个像素进行处理

从而使图像中的噪音得到减轻

## 运行方法
<<<<<<< HEAD
用pybind11库通过visualstudio生成器编译出动态链接库，将动态链接库（通常在Debug文件夹）复制一份到根目录。随后即可从main.py开始运行。
=======
在根目录创建一个名为extern的文件夹，[pybind11](https://github.com/pybind/pybind11)文件夹放在其中

通过cmake构建，构建工具选择visual studio生成器

将构建出来的动态链接库放在根目录，即可运行main.py
>>>>>>> a1a195370b51c5d5d2fc7028e669f3a8b46c6922
