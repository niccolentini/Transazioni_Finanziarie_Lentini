//
// Created by nicco on 13/07/21.
//
#ifndef TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
#define TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
using namespace std;
#include <utility>

#include "vector"
#include "iostream"
#include "fstream"
#include "Transaction.h"

class BankAccount {
public:

    explicit BankAccount(const int& n,const float& i = 0) : number(n) {
        balance += i;
    }

    void recharge(const float& r){
        if(r>0) {
            balance += r;
            cout<<"Operazione conclusa con successo!"<<endl;
        }
        else
            throw out_of_range("Non è possibile ricaricare.");
    }

    void withdraw(const float& r){
        if(r <= balance && r>0) {
            balance -= r;
            cout<<"Operazione conclusa con successo!"<<endl;
        }
        else if(r<0)
            throw out_of_range("Impossibile eseguire (valore < 0).");
        else
            throw out_of_range("Impossibile continuare, fuori limite.");
    }


    void nuovaTransazione (bool rec, BankAccount& b2, float amount, bool recv){
        if(number == b2.number){
            throw invalid_argument("I due conti risultano essere lo stesso. Impossibile eseguire operazione."); //controllo sugli indirizzi
        }
        else {
            if (rec) {
                if (amount <= b2.getBalance() && amount > 0) {
                    balance += amount;
                    b2.balance -= amount;
                } else if (amount < 0)
                    throw out_of_range("Impossibile eseguire (valore < 0).");                                  //controllo sull'importo
                else
                    throw out_of_range("Credito insufficiente per effettuare la nuovaTransazione");
            } else {
                if (amount <= balance && amount > 0) {
                    balance -= amount;
                    b2.balance += amount;
                } else if (amount < 0)
                    throw out_of_range("Impossibile eseguire (valore < 0)...");
                else
                    throw out_of_range("Credito insufficiente per effettuare la nuovaTransazione");
            }

            Transaction t(number, b2.getBankAccountNumber(), amount, "data nuovaTransazione", rec);
            transazioni.push_back(&t);
            b2.transazioni.push_back(&t);

            if (recv) {
                ofstream tfile;
                tfile.open("transazioni.txt", ios::app);
                tfile << "ID sender: " << t.getSender() << "\n ID receiver: " << t.getReceiver() << "\n Amount: " << t.getAmount()
                      << "$" << "\n Data: " << t.getData() << "\n\n";
                tfile.close();
            }
        }
    }

    int getBankAccountNumber() const {
        return number;
    }

    float getBalance() const {
        return balance;
    }

    void info() const{
        cout<<"Bank Account number: "<<number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    bool operator ==(int n) const{
        if(number == n)
            return true;
        else
            return false;
    }

    void loadTransactions(){
        ofstream tfile;
        tfile.open("transazioni_conto.txt", ios::app);
        for (auto itr : transazioni) {
            tfile << "ID sender: " << itr->getSender() << "\n ID receiver: " << itr->getReceiver() << "\n Amount: " << itr->getAmount() << "$"
                  << "\n Data: " << itr->getData()<<"\n\n";
        }
        tfile.close();
        cout<<"File con lista delle transazioni generato con successo! \n Per visualizzarlo nel terminale premere 0, premere 1 altrimenti."<<endl;
        int es;
        cin>>es;
        if(es == 0){
            ifstream cfile;
            cfile.open("transazioni_conto.txt");
            cout<<endl;
            string line;
            while( getline (cfile, line)){
                cout<<line<<endl;
            }
            cfile.close();
        }
    }

    int vectorTransactionSize() const{
        return transazioni.size();
    }
private:
    const int number;
    float balance{0};
    vector<Transaction*> transazioni;
};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
