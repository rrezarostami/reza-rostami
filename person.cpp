#include "Person.h"
Person::Person(string& firstName, string& lastName, string& nationalID, int birthYear, char gender){
    this->firstName = firstName;
    this->lastName = lastName;
    this->nationalID = nationalID;
    this->birthYear = birthYear;
    this->gender = gender;
}
Person::~Person() {}
string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

string Person::getNationalID(){
    return nationalID;
}

int Person::getBirthYear(){
    return birthYear;
}

char Person::getGender(){
    return gender;
}
void Person::showInfo(){
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "National ID: " << nationalID << endl;
    cout << "Birth Year: " << birthYear << endl;
    cout << "Gender: " << gender << endl;
}
