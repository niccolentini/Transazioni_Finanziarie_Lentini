//
// Created by nicco on 13/07/21.
//

#ifndef TRANSAZIONIFINANZIARIE_BANK_H
#define TRANSAZIONIFINANZIARIE_BANK_H
using namespace std;

#include <vector>
#include "string"
#include "User.h"
#include "list"
#include "map"
#include "BankAccount.h"
#include "algorithm"
#include "memory"

class Bank {
public:
    Bank(const string& n,const string& tn,const string& a) : name(n), telephoneNumber(tn) {
        addresses.push_back(a);
    }

    void addAddress(string a){
        addresses.push_back(a);
    }

    BankAccount newBankAccount (User & nu, float init = 0){
        bankAccountNumber++;
        BankAccount bA(bankAccountNumber, init);
        bankAccounts.insert(make_pair(bankAccountNumber, bA));
        auto bankptr = std::make_shared<BankAccount>(bA);
        nu.addBankAccount(bankptr);

        auto el = find(clients.begin(), clients.end(), &nu);
        if(el != clients.end()) {
            clients.push_back(&nu);
        }
        return bA;
    }

    const string &getName() const {
        return name;
    }

    const string &getTelephoneNumber() const {
        return telephoneNumber;
    }

    const vector<string> &getAddresses() const {
        return addresses;
    }


private:
    string name;
    string telephoneNumber;
    vector<string> addresses;

    list<User*> clients;
    static int bankAccountNumber; // variabile statica che attribuisce numero del conto corrente alla sua inizializzazione
    map<int, BankAccount> bankAccounts;

};


#endif //TRANSAZIONIFINANZIARIE_BANK_H
