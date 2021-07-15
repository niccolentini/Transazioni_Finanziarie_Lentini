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

class Bank {
public:
    Bank(string n, string tn, string a) : name(n), telephoneNumber(tn) {
        addresses.push_back(a);
    }

    void addAddress(string a){
        addresses.push_back(a);
    }

    BankAccount newBankAccount (User & nu, float init = 0){
        bankAccountNumber++;
        BankAccount bA(bankAccountNumber, init);
        bankAccounts.insert(make_pair(bankAccountNumber, bA));

        nu.bankaccount.push_back(&bA);

        auto el = find(clients.begin(), clients.end(), &nu);
        if(el != clients.end())
            clients.push_back(&nu);

        nu.addAccount();
        return bA;

    }

    void removeBankAccount(int & nBA){
        bankAccounts.erase(nBA);
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
