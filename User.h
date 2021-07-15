//
// Created by nicco on 13/07/21.
//

#ifndef TRANSAZIONIFINANZIARIE_USER_H
#define TRANSAZIONIFINANZIARIE_USER_H
using namespace std;
#include "string"
#include "BankAccount.h"

class User {
public:
    User(string n, string s, string tn, string a) : name(n), surname(s), telephoneNumber(tn), address(a){}

    void addAccount(){
        n_accounts++;
    }


    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        User::name = name;
    }
    const string &getSurname() const {
        return surname;
    }
    void setSurname(const string &surname) {
        User::surname = surname;
    }
    const string &getTelephoneNumber() const {
        return telephoneNumber;
    }
    void setTelephoneNumber(const string &telephoneNumber) {
        User::telephoneNumber = telephoneNumber;
    }
    const string &getAddress() const {
        return address;
    }
    void setAddress(const string &address) {
        User::address = address;
    }

    vector<BankAccount*> bankaccount;

private:
    string name;
    string surname;
    string telephoneNumber;
    string address;
    int n_accounts{0};
};


#endif //TRANSAZIONIFINANZIARIE_USER_H
