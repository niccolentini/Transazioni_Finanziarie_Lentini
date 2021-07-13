//
// Created by nicco on 13/07/21.
//
#ifndef TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
#define TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
using namespace std;
#include "vector"
#include "User.h"

struct Transaction {
    Transaction(int s, int r, float a, string d, bool re){
        sender=s;
        receiver=r;
        amount=a;
        data=d;
        received=re;
    }
    int sender;
    int receiver;
    float amount;
    string data;
    bool received;
};


class BankAccount {
public:
    BankAccount(User& ow, int n, float i = 0) : owner(&ow), number(n) {
        balance += i;
    }

    void Transazione (bool rec, BankAccount& b2, float amount){
        Transaction t (number, b2.getNumber(), amount, "data", rec);
        transazioni.push_back(t);
        b2.transazioni.push_back(t);

        if(rec) {
            balance += amount;
            b2.balance -= amount;
        }
        else{
            balance -= amount;
            b2.balance += amount;
        }

    }

    User *getOwner() const {
        return owner;
    }

    int getNumber() const {
        return number;
    }

    float getBalance() const {
        return balance;
    }

private:
    User* owner;
    const int number;
    float balance{0};
    vector<Transaction> transazioni;
};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
