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

    string recharge(const float& r){
        string result;
        if(r>0) {
            balance += r;
            result = "Operazione conclusa con successo!";
        }
        else
            result = "Impossibile ricaricare (valore < 0)...";

        return result;
    }

    string withdraw(const float& r){
        string result;
        if(r <= balance && r>0) {
            balance -= r;
            result="Operazione conclusa con successo!";
        }
        else if(r<0)
            result = "Impossibile eseguire (valore < 0)...";
        else
            result = "Impossibile continuare, fuori limite.";

    return result;
    }


    string transazione (const bool& rec, BankAccount& b2,const float& amount, const bool& recv){
        Transaction t (number, b2.getNumber(), amount, "data transazione", rec);
        transazioni.push_back(t);
        b2.transazioni.push_back(t);
        string result = "Operazione eseguita con successo!";
        if(rec) {
            if(amount <= b2.getBalance() && amount>0) {
                balance += amount;
                b2.balance -= amount;
            }
            else if(amount<0)
                result = "Impossibile eseguire (valore < 0)...";
            else
                result = "Credito insufficiente per effettuare la transazione";
        }
        else{
            if(amount <= balance && amount>0) {
                balance -= amount;
                b2.balance += amount;
            }
            else if(amount<0)
                result = "Impossibile eseguire (valore < 0)...";
            else
                result = "Credito insufficiente per effettuare la transazione";
        }

        if(recv){
            ofstream tfile;
            tfile.open("transazioni.txt", ios::app);
            tfile<<"ID sender: "<<t.sender<<"\n ID receiver: "<<t.receiver<<"\n Amount: "<<t.amount<<"$"<<"\n Data: "<<t.data<<"\n\n";
            tfile.close();
        }
        return result;
    }

    int getNumber() const {
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

    void fileTransaction(){
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
            cfile.open("transazioniconto.txt");
            cout<<endl;
            cout<<"Lettura file transazioniconto.txt ...\n"<<endl;
            cout<<endl;

            string line;
            while( getline (cfile, line)){
                cout<<line<<"\n"<<endl;
            }
            cfile.close();
        }
    }
    vector<Transaction> transazioni;
private:
    const int number;
    float balance{0};

};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
