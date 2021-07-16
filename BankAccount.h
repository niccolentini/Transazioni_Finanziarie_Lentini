//
// Created by nicco on 13/07/21.
//
#ifndef TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
#define TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
using namespace std;
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

    BankAccount(int n, float i = 0) : number(n) {
        balance += i;
    }

    void recharge(const float& r){
        if(r>0) {
            balance += r;
            cout << "Operazione conclusa con successo!" << endl;
        }
        else
            cout<<"Impossibile ricaricare (valore < 0)..."<<endl;
    }

    void withdraw(const float& r){
        if(r <= balance) {
            balance -= r;
            cout<<"Operazione conclusa con successo!"<<endl;
        }
        else
            cout<<"Non puoi prelevare più di "<<balance<<"$"<<endl;
    }


    void transazione (const bool& rec, BankAccount& b2,const float& amount){
        Transaction t (number, b2.getNumber(), amount, "data transazione", rec);
        transazioni.push_back(t);
        b2.transazioni.push_back(t);

        if(rec) {
            if(amount <= b2.getBalance()) {
                balance += amount;
                b2.balance -= amount;
            }
            else
                cout<<"Credito insufficiente per effettuare la transazione"<<endl;
        }
        else{
            if(amount <= balance) {
                balance -= amount;
                b2.balance += amount;
            }
            else
                cout<<"Credito insufficiente per effettuare la transazione"<<endl;
        }

        cout<<"Vuoi salvare la ricevuta su un file? [S/n]"<<endl;
        string result;
        cin>>result;
        if(result == "S"){
            ofstream tfile;
            tfile.open("transazioni.txt", ios::app);
            tfile<<"ID sender: "<<t.sender<<"\n ID receiver: "<<t.receiver<<"\n Amount: "<<t.amount<<"$"<<"\n Data: "<<t.data;
            tfile.close();
        }
    }

    int getNumber() const {
        return number;
    }

    float getBalance() const {
        return balance;
    }

    void info(){
        cout<<"Bank Account number: "<<number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    bool operator ==(int n){
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
        if(es = 0){
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

private:
    const int number;
    float balance{0};
    vector<Transaction> transazioni;
};


#endif //TRANSAZIONIFINANZIARIE_BANKACCOUNT_H
