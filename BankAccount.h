//
// Created by nicco on 13/07/21.
//
#ifndef TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
#define TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
using namespace std;
#include "vector"
#include "User.h"
#include "iostream"

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

    void recharge(float r){
        if(r>0) {
            balance += r;
            cout << "Charged Succesfully!" << endl;
        }
        else
            cout<<"Charging not possible (value < 0)..."<<endl;
    }

    void withdraw(float r){
        if(r <= balance)
            balance -= r;
        else
            cout<<"You can't withdraw more than "<<balance<<"$"<<endl;
    }


    void transazione (bool rec, BankAccount& b2, float amount){
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

    void info(){
        cout<<"Bank Account owner: "<<owner->getName()<<" "<<owner->getSurname()<<endl;
        cout<<"Bank Account number: "<<number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

private:
    User* owner;
    const int number;
    float balance{0};
    vector<Transaction> transazioni;
};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
