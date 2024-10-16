#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>
#include <algorithm>
#include <mutex>

namespace py = pybind11;

// 简单中值滤波器实现
py::array_t<uint8_t> median_filter(py::array_t<uint8_t> input, int filter_size) {
    // 获取 numpy 数组的 buffer 信息
    py::buffer_info buf = input.request();

    // 输入图像的宽度、高度和通道数
    int height = buf.shape[0];
    int width = buf.shape[1];
    int channels = buf.shape[2];

    // 将数据指针转为 uint8_t 类型
    uint8_t* ptr = (uint8_t*) buf.ptr;

    // 创建输出数组
    auto result = py::array_t<uint8_t>(buf.size);
    uint8_t* out_ptr = (uint8_t*) result.request().ptr;

    // 处理滤波
    int half_size = filter_size / 2;

    // 遍历图像并应用滤波
    for (int c = 0; c < channels; ++c) { // 对每个通道进行处理
        for (int i = half_size; i < height - half_size; ++i) {
            for (int j = half_size; j < width - half_size; ++j) {
                std::vector<uint8_t> window;
                for (int x = -half_size; x <= half_size; ++x) {
                    for (int y = -half_size; y <= half_size; ++y) {
                        window.push_back(ptr[(i + x) * width * channels + (j + y) * channels + c]);
                    }
                }
                std::sort(window.begin(), window.end());
                out_ptr[i * width * channels + j * channels + c] = window[window.size() / 2];
            }
        }
    }
    
    return result.reshape({height, width, channels});
}

// 绑定模块和函数
PYBIND11_MODULE(filter, m) {
    m.def("median_filter", &median_filter, "A simple median filter", py::arg("input"), py::arg("filter_size"));
}
