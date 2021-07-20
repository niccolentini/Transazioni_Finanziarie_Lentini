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
        Transaction t (number, b2.getBankAccountNumber(), amount, "data nuovaTransazione", rec);
        transazioni.push_back(t);
        b2.transazioni.push_back(t);
        if(rec) {
            if(amount <= b2.getBalance() && amount>0) {
                balance += amount;
                b2.balance -= amount;
            }
            else if(amount<0)
                throw out_of_range("Impossibile eseguire (valore < 0).");
            else
                throw out_of_range("Credito insufficiente per effettuare la nuovaTransazione");
        }
        else{
            if(amount <= balance && amount>0) {
                balance -= amount;
                b2.balance += amount;
            }
            else if(amount<0)
                throw out_of_range("Impossibile eseguire (valore < 0)...");
            else
                throw out_of_range("Credito insufficiente per effettuare la nuovaTransazione");
        }

        if(recv){
            ofstream tfile;
            tfile.open("transazioni.txt", ios::app);
            tfile<<"ID sender: "<<t.sender<<"\n ID receiver: "<<t.receiver<<"\n Amount: "<<t.amount<<"$"<<"\n Data: "<<t.data<<"\n\n";
            tfile.close();
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
            tfile << "ID sender: " << itr.sender << "\n ID receiver: " << itr.receiver << "\n Amount: " << itr.amount << "$"
                  << "\n Data: " << itr.data<<"\n\n";
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
    vector<Transaction> transazioni;
};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
