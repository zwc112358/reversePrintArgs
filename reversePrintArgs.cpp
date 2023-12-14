#include <iostream>

// 定义一个模板函数 reversePrintArgs，接受一个元组 Tuple 和一个索引序列 sequence
template<typename Tuple, std::size_t... I>
void reversePrintArgs(Tuple&& t, std::index_sequence<I...>) {
    // 使用折叠表达式展开参数包，将参数反向输出到标准输出流
    ((std::cout << std::get<std::tuple_size_v<Tuple> - I - 1>(t) << ' '), ...);
}

// 定义一个模板函数 reversePrint，接受任意数量的参数（模板参数包 Args）
template<typename... Args>
void reversePrint(Args... args) {
    // 调用 reversePrintArgs 函数，传递参数包和对应的索引序列
    reversePrintArgs(std::make_tuple(args...), std::make_index_sequence<sizeof...(Args)>());
}

int main() {
    // 在主函数中调用 reversePrint 函数，传递整数 1、浮点数 2.1 和字符串 "312"
    reversePrint(1, 2.1, "312");
    
    return 0;
}
