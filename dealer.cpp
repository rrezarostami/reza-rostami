#include "Dealer.h"
#include <iostream>

Dealer::Dealer(string& dealerID, string& name, int establishmentYear, string& economicCode, string& ownerFirstName, string& ownerLastName, string& province, string& city){
    this->dealerID = dealerID;
    this->name = name;
    this->establishmentYear = establishmentYear;
    this->economicCode = economicCode;
    this->ownerFirstName = ownerFirstName;
    this->ownerLastName = ownerLastName;
    this->province = province;
    this->city = city;
}
Dealer::~Dealer() {}
string Dealer::getDealerID(){
    return dealerID;
}

string Dealer::getName(){
    return name;
}

int Dealer::getEstablishmentYear(){
    return establishmentYear;
}

string Dealer::getEconomicCode(){
    return economicCode;
}

string Dealer::getOwnerFirstName(){
    return ownerFirstName;
}

string Dealer::getOwnerLastName(){
    return ownerLastName;
}

string Dealer::getProvince(){
    return province;
}

string Dealer::getCity(){
    return city;
}

void Dealer::showInfo(){
    cout << "Dealer ID: " << dealerID << endl;
    cout << "Name: " << name << endl;
    cout << "Establishment Year: " << establishmentYear << endl;
    cout << "Economic Code: " << economicCode << endl;
    cout << "Owner: " << ownerFirstName << " " << ownerLastName << endl;
    cout << "Province: " << province << endl;
    cout << "City: " << city << endl;
}
