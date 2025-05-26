#include <iostream>
#include <string>
#pragma once
using namespace std;

class Person {
public:
    Person(string& firstName, string& lastName, string& nationalID, int birthYear, char gender);
    ~Person();
    string getFirstName();
    string getLastName();
    string getNationalID();
    int getBirthYear();
    char getGender();
    void showInfo();
private:
    string firstName;
    string lastName;
    string nationalID;
    int birthYear;
    char gender;
};