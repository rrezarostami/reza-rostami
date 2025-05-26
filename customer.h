#include <iostream>
#include <string>
#include "Person.h"
#pragma once
using namespace std;

class Customer : public Person {
public:
    Customer(string& firstName, string& lastName, string& nationalID, int birthYear, char gender, string& customerID, string& province, string& city);
    ~Customer();
    string getCustomerID();
    string getProvince();
    string getCity();
    void showInfo();

private:
    string customerID;
    string province;
    string city;
};