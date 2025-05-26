#include <iostream>
#include <string>

#include "Person.h"
#include "Customer.h"
#include "Product.h"
#include "Dealer.h"
#include "Purchase.h"

using namespace std;

const int MAX_PRODUCTS = 100;
const int MAX_CUSTOMERS = 100;
const int MAX_DEALERS = 100;
const int MAX_PURCHASES = 1000;


Product* products[MAX_PRODUCTS];
int productCount = 0;
Customer* customers[MAX_CUSTOMERS];
int customerCount = 0;
Dealer* dealers[MAX_DEALERS];
int dealerCount = 0;
Purchase* purchases[MAX_PURCHASES];
int purchaseCount = 0;


void addProduct();
void removeProduct();
void addCustomer();
void removeCustomer();
void addDealer();
void removeDealer();
void recordPurchase();
void calculateTotalPurchaseByCustomer();
void listCustomersOfProduct();
void listProductsByDealer();
void totalUnitsSoldOfProduct();
void productsPurchasedByCustomer();
void salesReportByDealer();

int main() {
    int choice;
    do {
        cout << "\n===== Main Menu =====" << endl;
        cout << "1. Add a Product" << endl;
        cout << "2. Remove a Product" << endl;
        cout << "3. Add a Customer" << endl;
        cout << "4. Remove a Customer" << endl;
        cout << "5. Add a Dealer" << endl;
        cout << "6. Remove a Dealer" << endl;
        cout << "7. Record a Purchase" << endl;
        cout << "8. Calculate total purchase of a Customer" << endl;
        cout << "9. List Customers of a Product" << endl;
        cout << "10. List Products sold by a Dealer" << endl;
        cout << "11. Total units sold of a Product" << endl;
        cout << "12. Products purchased by a Customer" << endl;
        cout << "13. Sales report by Dealer" << endl;
        cout << "14. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: addCustomer(); break;
            case 4: removeCustomer(); break;
            case 5: addDealer(); break;
            case 6: removeDealer(); break;
            case 7: recordPurchase(); break;
            case 8: calculateTotalPurchaseByCustomer(); break;
            case 9: listCustomersOfProduct(); break;
            case 10: listProductsByDealer(); break;
            case 11: totalUnitsSoldOfProduct(); break;
            case 12: productsPurchasedByCustomer(); break;
            case 13: salesReportByDealer(); break;
            case 14: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 14);
    for (int i = 0; i < productCount; i++) delete products[i];
    for (int i = 0; i < customerCount; i++) delete customers[i];
    for (int i = 0; i < dealerCount; i++) delete dealers[i];
    for (int i = 0; i < purchaseCount; i++) delete purchases[i];

    return 0;
}
bool existsProductID(const string& id) {
    for (int i = 0; i < productCount; i++)
        if (products[i]->getProductID() == id)
            return true;
    return false;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) { cout << "Product array full." << endl; return; }
    string id, name, brand;
    double price, weight;
    cout << "Enter product ID: "; cin >> id;
    if (existsProductID(id)) { cout << "ID already exists." << endl; return; }
    cout << "Enter name: "; cin >> name;
    cout << "Enter price: "; cin >> price;
    cout << "Enter brand: "; cin >> brand;
    cout << "Enter weight: "; cin >> weight;
    products[productCount++] = new Product(id, name, price, brand, weight);
    cout << "Product added." << endl;
}

void removeProduct() {
    if (productCount == 0) { cout << "No products." << endl; return; }
    string id; cout << "Enter product ID to remove: "; cin >> id;
    int idx = -1;
    for (int i = 0; i < productCount; i++)
        if (products[i]->getProductID() == id) { idx = i; break; }
    if (idx < 0) { cout << "Not found." << endl; return; }
    delete products[idx];
    for (int i = idx; i < productCount - 1; i++) products[i] = products[i+1];
    productCount--;
    for (int i = 0; i < purchaseCount; ) {
        if (purchases[i]->getProduct().getProductID() == id) {
            delete purchases[i];
            for (int j = i; j < purchaseCount - 1; j++) purchases[j] = purchases[j+1];
            purchaseCount--;
        } else i++;
    }
    cout << "Product and related purchases removed." << endl;
}

bool existsCustomerID(const string& cid) {
    for (int i = 0; i < customerCount; i++)
        if (customers[i]->getCustomerID() == cid)
            return true;
    return false;
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) { cout << "Customer array full." << endl; return; }
    string fn, ln, nid, cid, prov, city;
    int year; char g;
    cout << "First name: "; cin >> fn;
    cout << "Last name: "; cin >> ln;
    cout << "National ID: "; cin >> nid;
    cout << "Birth year: "; cin >> year;
    cout << "Gender (M/F): "; cin >> g;
    cout << "Customer ID: "; cin >> cid;
    if (existsCustomerID(cid)) { cout << "ID exists." << endl; return; }
    cout << "Province: "; cin >> prov;
    cout << "City: "; cin >> city;
    customers[customerCount++] = new Customer(fn, ln, nid, year, g, cid, prov, city);
    cout << "Customer added." << endl;
}

void removeCustomer() {
    if (customerCount == 0) { cout << "No customers." << endl; return; }
    string cid; cout << "Customer ID to remove: "; cin >> cid;
    int idx = -1;
    for (int i = 0; i < customerCount; i++)
        if (customers[i]->getCustomerID() == cid) { idx = i; break; }
    if (idx < 0) { cout << "Not found." << endl; return; }
    delete customers[idx];
    for (int i = idx; i < customerCount - 1; i++) customers[i] = customers[i+1];
    customerCount--;
    for (int i = 0; i < purchaseCount; ) {
        if (purchases[i]->getCustomer().getCustomerID() == cid) {
            delete purchases[i];
            for (int j = i; j < purchaseCount - 1; j++) purchases[j] = purchases[j+1];
            purchaseCount--;
        } else i++;
    }
    cout << "Customer and related purchases removed." << endl;
}

bool existsDealerID(const string& did) {
    for (int i = 0; i < dealerCount; i++)
        if (dealers[i]->getDealerID() == did)
            return true;
    return false;
}

void addDealer() {
    if (dealerCount >= MAX_DEALERS) { cout << "Dealer array full." << endl; return; }
    string id, name, econ, ofn, eln, prov, city;
    int year;
    cout << "Dealer ID: "; cin >> id;
    if (existsDealerID(id)) { cout << "ID exists." << endl; return; }
    cout << "Name: "; cin >> name;
    cout << "Establishment Year: "; cin >> year;
    cout << "Economic Code: "; cin >> econ;
    cout << "Owner First Name: "; cin >> ofn;
    cout << "Owner Last Name: "; cin >> eln;
    cout << "Province: "; cin >> prov;
    cout << "City: "; cin >> city;
    dealers[dealerCount++] = new Dealer(id, name, year, econ, ofn, eln, prov, city);
    cout << "Dealer added." << endl;
}

void removeDealer() {
    if (dealerCount == 0) { cout << "No dealers." << endl; return; }
    string id; cout << "Dealer ID to remove: "; cin >> id;
    int idx = -1;
    for (int i = 0; i < dealerCount; i++)
        if (dealers[i]->getDealerID() == id) { idx = i; break; }
    if (idx < 0) { cout << "Not found." << endl; return; }
    delete dealers[idx];
    for (int i = idx; i < dealerCount - 1; i++) dealers[i] = dealers[i+1];
    dealerCount--;
    for (int i = 0; i < purchaseCount; ) {
        if (purchases[i]->getDealer().getDealerID() == id) {
            delete purchases[i];
            for (int j = i; j < purchaseCount - 1; j++) purchases[j] = purchases[j+1];
            purchaseCount--;
        } else i++;
    }
    cout << "Dealer and related purchases removed." << endl;
}

void recordPurchase() {
    if (purchaseCount >= MAX_PURCHASES) { cout << "Purchase array full." << endl; return; }
    if (customerCount == 0 || productCount == 0 || dealerCount == 0) {
        cout << "Need at least one product, customer, dealer." << endl;
        return;
    }
    string pid, cid, prid, did, date;
    double qty;
    cout << "Purchase ID: "; cin >> pid;
    cout << "Customer ID: "; cin >> cid;
    cout << "Product ID: "; cin >> prid;
    cout << "Dealer ID: "; cin >> did;
    cout << "Quantity: "; cin >> qty;
    cout << "Date (YYYY-MM-DD): "; cin >> date;
    Customer* pc = nullptr; Product* pp = nullptr; Dealer* pd = nullptr;
    for (int i = 0; i < customerCount; i++) if (customers[i]->getCustomerID() == cid) pc = customers[i];
    for (int i = 0; i < productCount; i++) if (products[i]->getProductID() == prid) pp = products[i];
    for (int i = 0; i < dealerCount; i++) if (dealers[i]->getDealerID() == did) pd = dealers[i];
    if (!pc || !pp || !pd || qty <= 0) { cout << "Invalid data." << endl; return; }
    purchases[purchaseCount++] = new Purchase(pid, *pc, *pp, *pd, qty, date);
    cout << "Purchase recorded." << endl;
}

void calculateTotalPurchaseByCustomer() {
    string cid; cout << "Customer ID: "; cin >> cid;
    double total = 0;
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getCustomer().getCustomerID() == cid) {
            total += purchases[i]->getQuantity() * purchases[i]->getProduct().getPrice();
        }
    }
    cout << "Total purchase: " << total << endl;
}

void listCustomersOfProduct() {
    string prid; cout << "Product ID: "; cin >> prid;
    cout << "Customers:\n";
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getProduct().getProductID() == prid) {
            purchases[i]->getCustomer().showInfo();
            cout << "---\n";
        }
    }
}

void listProductsByDealer() {
    string did; cout << "Dealer ID: "; cin >> did;
    cout << "Products:\n";
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getDealer().getDealerID() == did) {
            purchases[i]->getProduct().showInfo();
            cout << "---\n";
        }
    }
}

void totalUnitsSoldOfProduct() {
    string prid; cout << "Product ID: "; cin >> prid;
    double sum = 0;
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getProduct().getProductID() == prid) sum += purchases[i]->getQuantity();
    }
    cout << "Units sold: " << sum << endl;
}

void productsPurchasedByCustomer() {
    string cid; cout << "Customer ID: "; cin >> cid;
    cout << "Products:\n";
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getCustomer().getCustomerID() == cid) {
            purchases[i]->getProduct().showInfo();
            cout << "---\n";
        }
    }
}

void salesReportByDealer() {
    string did; cout << "Dealer ID: "; cin >> did;
    double total = 0;
    for (int i = 0; i < purchaseCount; i++) {
        if (purchases[i]->getDealer().getDealerID() == did) {
            total += purchases[i]->getQuantity() * purchases[i]->getProduct().getPrice();
        }
    }
    cout << "Sales total: " << total << endl;
}