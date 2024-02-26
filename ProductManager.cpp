#define PRODUCT_MANAGER
#include <iostream>
#include <limits>
//#include "Product.cpp"
#include "SearchProduct.cpp"

class ProductManager
{
private:
    Product prod;

    int exceptionHandler() {
        int choice;
        std::cin >> choice;

        while (std::cin.fail() || choice < 1 || choice > 6) {
            // Clear the error flag
            std::cin.clear();
            // Discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Notify user of the error and ask again
            std::cout << "Invalid choice. Please enter a number between 1 and 6: ";
            std::cin >> choice;
        }

        return choice;
    }

public:
    int getMenu(){
        std::cout << "Select an option from the menu below:" << std::endl;
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Search Product By Name" << std::endl;
        std::cout << "3. Search Product By Category" << std::endl;
        std::cout << "4. Search Product By Brand" << std::endl;
        std::cout << "5. Update Product" << std::endl;
        std::cout << "6. Delete Product" << std::endl;

        std::cout << "Enter your choice (1-6): ";
        int choice = exceptionHandler();

        switch(choice) {
            case 1:
                {
                    std::cout << "Enter the name of the product you want to search: ";
                    prod.createProduct();
                    // Now you can do something with the searchResults
                }

                break;
            case 2:
                {
                    std::cout << "Enter the name of the product you want to search : ";
                    SearchProduct search;
                    std::string nameToSearch;
                    std::cin >> nameToSearch;// You need to get the name from the user
                    std::vector<Product> searchResults = search.searchByName(nameToSearch);
                    // Now you can do something with the searchResults
                }
                // code block
                break;
            case 3:
                {
                    std::cout << "Enter the product category that you want to search : ";
                    SearchProduct search;
                    std::string categoryToSearch;
                    std::cin >> categoryToSearch;// You need to get the name from the user
                    std::vector<Product> searchResults = search.searchByCategory(categoryToSearch);
                    // Now you can do something with the searchResults
                }
                // code block
                break;
            case 4:
                {
                    std::cout << "Enter the product brand that you want to search : ";
                    SearchProduct search;
                    std::string brandToSearch;
                    std::cin >> brandToSearch;// You need to get the name from the user
                    std::vector<Product> searchResults = search.searchByBrand(brandToSearch);
                    // Now you can do something with the searchResults
                }
                // code block
                break;
            case 5:
                // code block
                break;
            case 6:
                // code block
                break;
            }
    }

    void addProduct(){
        // TODO add code to add product and
        // store the product to products.json file by using Product class and FileHandler class
    }

    void updateProduct(){
        // TODO add code to update a product
    }

    void deleteProduct(){
        // TODO add code to delete a product
    }

};
int main()
{
    ProductManager manager;

    std::cout << "Welcome to the Product Manager!" << std::endl << std::endl;

    int choice;

    choice = manager.getMenu();


    return 0;
}
