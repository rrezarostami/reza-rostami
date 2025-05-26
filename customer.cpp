#include "Customer.h"
Customer::Customer(string& firstName, string& lastName, string& nationalID, int birthYear, char gender, string& customerID, string& province, string& city)
    : Person(firstName, lastName, nationalID, birthYear, gender){
    this->customerID = customerID;
    this->province = province;
    this->city = city;
}
Customer::~Customer() {}
string Customer::getCustomerID(){
    return customerID;
}

string Customer::getProvince(){
    return province;
}

string Customer::getCity(){
    return city;
}
void Customer::showInfo(){
    Person::showInfo();
    cout << "Customer ID: " << customerID << endl;
    cout << "Province: " << province << endl;
    cout << "City: " << city << endl;
}
