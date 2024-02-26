#include <algorithm>
#include "FileHandler.cpp"

class SearchProduct
{
private:
    string filename;

public:
    string searchText;
    FileHandler fHandler;

    string to_lowercase(const string& text) {
        string lowercase_text = text;
        transform(lowercase_text.begin(), lowercase_text.end(), lowercase_text.begin(), ::tolower);
        return lowercase_text;
    }


    vector<Product> searchByName(string name) {
        vector<Product> results;
        vector<Product> productList = fHandler.readJsonFile();

        string lowercaseName = to_lowercase(name);

        for (const Product& product : productList) {
            string lowercaseProductName = to_lowercase(product.getName());
            if (lowercaseProductName.find(lowercaseName) != string::npos) {
                results.push_back(product);
            }
            cout << "Product now : " << lowercaseProductName << endl;


        }
        showSearchResult(results, name);

        cout << "Byanze ariko name wa searchinze ni : " << lowercaseName << endl;

        return results;
    }



    vector<Product> searchByCategory(string category) {
        vector<Product> results;
        vector<Product> productList = fHandler.readJsonFile();

        string lowercaseCategory = to_lowercase(category);

        for (const Product& product : productList) {
            string lowercaseProductCategory = to_lowercase(product.getCategory());
            if (lowercaseProductCategory.find(lowercaseCategory) != string::npos) {
                results.push_back(product);
            }

        }
        showSearchResult(results, category);

        cout << "Byanze ariko category wa searchinze ni : " << lowercaseCategory << endl;

        return results;
    }

    vector<Product> searchByBrand(string brand) {
        vector<Product> results;
        vector<Product> productList = fHandler.readJsonFile();

        string lowercaseBrand = to_lowercase(brand);

        for (const Product& product : productList) {
            string lowercaseProductBrand = to_lowercase(product.getBrand());
            if (lowercaseProductBrand.find(lowercaseBrand) != string::npos) {
                results.push_back(product);
            }

        }
        showSearchResult(results, brand);

        cout << "Byanze ariko brand wa searchinze ni : " << lowercaseBrand << endl;

        return results;
    }




    void showSearchResult(const vector<Product>& plist, const string& sTxt) {
        cout << "Search results for '" << sTxt << "':" << endl;

        if (plist.empty()) {
            cout << "No products found." << endl;
            return;
        }

        for (const Product& product : plist) {
            cout << "Name: " << product.getName() << endl;
            cout << "Brand: " << product.getBrand() << endl;
            //cout << "Description: " << product.getDescription() << endl;
            // Add other fields as needed

            cout << "--------------------------------" << endl;
        }
    }

};
