CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall

.PHONY: all test clean

all: ProductManager.exe

ProductManager.exe: ProductManager.cpp
	$(CXX) $(CXXFLAGS) ProductManager.cpp -o ProductManager.exe

test: tests/test_product.exe tests/test_search_product.exe
	./tests/test_product.exe
	./tests/test_search_product.exe

tests/test_product.exe: tests/test_product.cpp Product.cpp
	$(CXX) $(CXXFLAGS) tests/test_product.cpp -o tests/test_product.exe

tests/test_search_product.exe: tests/test_search_product.cpp SearchProduct.cpp FileHandler.cpp Product.cpp
	$(CXX) $(CXXFLAGS) tests/test_search_product.cpp -o tests/test_search_product.exe

clean:
	rm -f ProductManager.exe tests/test_product.exe tests/test_search_product.exe
