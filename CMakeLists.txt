cmake_minimum_required(VERSION 3.23)
project(filter) # 设置项目名称

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PYTHON_EXECUTABLE "D:/Program Files/Python/3.12/python.exe")
set(PYTHON_LIBRARY "D:/Program Files/Python/3.12/libs/python312.lib")
set(PYTHON_INCLUDE_DIR "D:/Program Files/Python/3.12/include")


add_subdirectory(extern/pybind11)
pybind11_add_module(filter filter.cpp)