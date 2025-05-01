#include <iostream>

template<typename... Types>
void function(Types... args) {
    (std::cout << ... << args);
    std::cout << std::endl;
}

template <typename T> 
class Base {
    T a;
};

template<>
class Base<int> {
    int a;
};


template<typename T, typename... Rest>
void printAll(T first, Rest... rest) {
    std::cout << first << " ";
    if constexpr (sizeof...(rest) > 0)
        printAll(rest...);
}


template<typename T>
struct is_pointer {
    static const bool value = false;
};

// Chuyên biệt hóa: là con trỏ
template<typename T>
struct is_pointer<T*> {
    static const bool value = true;
};

int main() {
    std::cout << is_pointer<int>::value << "\n";   // 0
    std::cout << is_pointer<int*>::value << "\n"; 
}