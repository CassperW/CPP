#include <iostream> // For std::cout, std::endl, std::cerr
#include <cstring>  // For strlen, strcpy
#include <cstddef>  // For size_t

struct ManualString {
    char* data;   
    size_t len;   
};

ManualString gives_ownership_manual() {
    const char* source = "Rust";
    size_t source_len = std::strlen(source);

    // 1. 手动在堆上分配内存
    // +1 是为了存储字符串末尾的 null 终止符 '\0'
    char* buffer = new (std::nothrow) char[source_len + 1]; // 使用 nothrow 避免 new 失败时抛出异常

    // 检查内存分配是否成功
    if (buffer == nullptr) {
        std::cerr << "Memory allocation failed in gives_ownership_manual!" << std::endl;
        // 在实际应用中，这里需要更完善的错误处理。
        // 这里为了简单，返回一个空的 ManualString
        return {nullptr, 0};
    }

    // 2. 将字符串数据复制到分配的内存中
    std::strcpy(buffer, source); // strcpy 会自动复制 null 终止符

    // 3. 创建 ManualString 结构体，并将指针和长度存储进去
    ManualString result = {buffer, source_len};

    // 4. 返回结构体。
    // 注意：返回结构体是按值复制的，但复制的是结构体成员 (data 指针和 len)。
    // 堆上的字符串数据本身没有被复制。
    // 调用者获得了这个指针，从而获得了“拥有这块内存”的责任。
    return result;
}

// 对应 Rust 的 fn main()
int main() {
    ManualString s = gives_ownership_manual();

    if (s.data != nullptr) {
        std::cout << "String data: " << s.data << std::endl;
        
        delete[] s.data;

        s.data = nullptr;
        s.len = 0; // 长度也清零
    } else {
         std::cerr << "Failed to get string data." << std::endl;
         return 1;
    }

    return 0; // 成功结束
}