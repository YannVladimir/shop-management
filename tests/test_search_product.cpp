// Standalone test binary: compiled directly (matches this project's existing
// pattern of #include-ing .cpp files instead of linking separate object
// files; SearchProduct.cpp -> FileHandler.cpp -> Product.cpp all become one
// translation unit, same as ProductManager.cpp does for the real app).
#include <cassert>
#include <iostream>
#include "../SearchProduct.cpp"

int main() {
    SearchProduct search;

    assert(search.to_lowercase("HELLO") == "hello");
    assert(search.to_lowercase("MiXeD Case 123") == "mixed case 123");
    assert(search.to_lowercase("") == "");
    assert(search.to_lowercase("already lower") == "already lower");

    std::cout << "test_search_product: all assertions passed" << std::endl;
    return 0;
}
