#pragma once
#include <string>
using namespace std;

class Dealer {
public:
    Dealer(string& dealerID, string& name, int establishmentYear, string& economicCode, string& ownerFirstName, string& ownerLastName, string& province, string& city);
    ~Dealer();
    string getDealerID();
    string getName();
    int getEstablishmentYear();
    string getEconomicCode();
    string getOwnerFirstName();
    string getOwnerLastName();
    string getProvince();
    string getCity();
    void showInfo();

private:
    string dealerID;
    string name;
    int establishmentYear;
    string economicCode;
    string ownerFirstName;
    string ownerLastName;
    string province;
    string city;
};