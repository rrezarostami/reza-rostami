#include "Purchase.h"
Purchase::Purchase(string& purchaseID, const Customer& customer, const Product& product, const Dealer& dealer, double quantity, string& purchaseDate)
        :customer(customer), product(product), dealer(dealer), quantity(quantity){
    this->purchaseID = purchaseID;
    this->purchaseDate = purchaseDate;
    if (quantity <= 0) {
        cout << "Error: Quantity must be positive." << endl;
        return;
    }
}
Purchase::~Purchase() {}
string Purchase::getPurchaseID(){
    return purchaseID;
}

Customer Purchase::getCustomer(){
    return customer;
}

Product Purchase::getProduct(){
    return product;
}

Dealer Purchase::getDealer(){
    return dealer;
}

double Purchase::getQuantity(){
    return quantity;
}

string Purchase::getPurchaseDate(){
    return purchaseDate;
}
void Purchase::showInfo(){
    cout << "Purchase ID: " << purchaseID << endl;
    cout << "Date: " << purchaseDate << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "-- Customer Info --" << endl;
    customer.showInfo();
    cout << "-- Product Info --" << endl;
    product.showInfo();
    cout << "-- Dealer Info --" << endl;
    dealer.showInfo();
}
