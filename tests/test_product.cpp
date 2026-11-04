#include <cassert>
#include <iostream>
#include <set>
#include "../Product.cpp"

int main() {
    Product p;

    // generateUniqueCode() should only use alphanumeric characters.
    std::string code = p.generateUniqueCode();
    for (char c : code) {
        assert(isalnum(static_cast<unsigned char>(c)));
    }

    // Repeated calls should (overwhelmingly likely) differ from one another.
    std::set<std::string> codes;
    for (int i = 0; i < 20; i++) {
        codes.insert(p.generateUniqueCode());
    }
    assert(codes.size() > 1);

    std::cout << "test_product: all assertions passed" << std::endl;
    return 0;
}
