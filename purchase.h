#include <iostream>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "Dealer.h"

using namespace std;

class Purchase {
public:
    Purchase(string& purchaseID,const Customer& customer,const Product& product,const Dealer& dealer, double quantity,string& purchaseDate);
    ~Purchase();
    string getPurchaseID();
    Customer getCustomer();
    Product getProduct();
    Dealer getDealer();
    double getQuantity();
    string getPurchaseDate();
    void showInfo();

private:
    string purchaseID;
    Customer customer;
    Product product;
    Dealer dealer;
    double quantity;
    string purchaseDate;
};
