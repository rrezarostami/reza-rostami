#include <iostream>
#include <string>
#pragma once
using namespace std;

class Product {
public:
    Product(string& productID, string& name, double price, string& brand, double weight);
    ~Product();
    string getProductID();
    string getName();
    double getPrice();
    string getBrand();
    double getWeight();
    void showInfo();
private:
    string productID;
    string name;
    double price;
    string brand;
    double weight;
};