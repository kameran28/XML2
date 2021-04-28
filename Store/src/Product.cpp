#include <iostream>
using namespace std;

/* Product class with all the properties */

class Product {
public:
    Product(string name, double price, string description, string image_url) {
        this->name = name;
        this->price = price;
        this->description = description;
        this->image_url = image_url;
    }
    
    int id;
    string name;
    double price;
    string description;
    string image_url;
};
