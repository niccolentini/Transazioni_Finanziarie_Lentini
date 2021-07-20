//
// Created by nicco on 13/07/21.
//

#ifndef TRANSAZIONIFINANZIARIE_USER_H
#define TRANSAZIONIFINANZIARIE_USER_H
using namespace std;
#include "string"
#include "BankAccount.h"
#include "memory"

class User {
public:
    User(const string& n, const string& s, const string& tn, const  string& a) : name(n), surname(s), telephoneNumber(tn), address(a){}

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }
    void setSurname(const string &Surname) {
        User::surname = Surname;
    }
    const string &getTelephoneNumber() const {
        return telephoneNumber;
    }

    const string &getAddress() const {
        return address;
    }

    void addBankAccount (const shared_ptr<BankAccount>& bA){
        bankaccount.push_back(bA);
    }

    int bankAccountVectorSize(){
        return bankaccount.size();
    }

    shared_ptr<BankAccount>& findBankAccount(int n){
        if (n > bankaccount.size() || n < 0)
            throw out_of_range("Conto inesistente.");
        return bankaccount[n];
    }

private:
    string name;
    string surname;
    string telephoneNumber;
    string address;

    vector<shared_ptr<BankAccount>> bankaccount;
};


#endif //TRANSAZIONIFINANZIARIE_USER_H
