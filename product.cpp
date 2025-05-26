#include "Product.h"
Product::Product(string& productID, string& name, double price, string& brand, double weight){
    if (price <= 0) {
        cout << "Error: Price must be positive." << endl;
        return;
    }
    if (weight <= 0) {
        cout << "Error: Weight must be positive." << endl;
        return;
    }
}
Product::~Product() {}

string Product::getProductID(){
    return productID;
}

string Product::getName(){
    return name;
}

double Product::getPrice(){
    return price;
}

string Product::getBrand(){
    return brand;
}

double Product::getWeight(){
    return weight;
}
void Product::showInfo(){
    cout << "Product ID: " << productID << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Brand: " << brand << endl;
    cout << "Weight: " << weight << endl;
}
