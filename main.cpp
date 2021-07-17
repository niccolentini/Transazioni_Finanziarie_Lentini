using namespace std;

#include <iostream>
#include <string>
#include "Bank.h"
#include "User.h"
#include "algorithm"
#include <fstream>

int Bank::bankAccountNumber = 0;



int main() {
    map<int, User*> users;
    map<string, Bank*> banks;
    map<int, BankAccount*> bankaccounts;

    int iduser = 0;

    User user1 ("Paul", "James", "455589049", "21st Avenue");
    iduser++;
    users.insert(make_pair(iduser, &user1));
    User user2("Anna", "Lawry", "7768357509", "Fulton Street");
    iduser++;
    users.insert(make_pair(iduser, &user2));
    User user3("Larry", "Howard", "3351705576", "Libbey Avenue");
    iduser++;
    users.insert(make_pair(iduser, &user3));

    cout<<"Users: "<<"\n"<<user1.getName()<<" "<<user1.getSurname()<<"\n"<<user2.getName()<<" "<<user2.getSurname()<<user3.getName()<<" "<<user3.getSurname()<<endl;

    Bank bank1("AmericanExpress", "3334445565", "New York");
    banks.insert(make_pair(bank1.getName(), &bank1));
    Bank bank2("HSBC", "441226261010", "London, UK");
    banks.insert(make_pair(bank2.getName(), &bank2));
    Bank bank3("Fineco", "4449574839", "Roma");
    banks.insert(make_pair(bank3.getName(), &bank3));



    BankAccount bA1 = bank1.newBankAccount(user1, 500);
    bankaccounts.insert(make_pair(bA1.getNumber(), &bA1));
    BankAccount bA2 = bank1.newBankAccount(user2, 500);
    bankaccounts.insert(make_pair(bA2.getNumber(), &bA2));
    BankAccount bA3 = bank2.newBankAccount(user3, 500);
    bankaccounts.insert(make_pair(bA3.getNumber(), &bA3));
    BankAccount bA4 = bank2.newBankAccount(user1, 500);
    bankaccounts.insert(make_pair(bA4.getNumber(), &bA4));
    BankAccount bA5 = bank3.newBankAccount(user1, 500);
    bankaccounts.insert(make_pair(bA5.getNumber(), &bA5));
    BankAccount bA6 = bank3.newBankAccount(user2, 500);
    bankaccounts.insert(make_pair(bA6.getNumber(), &bA6));

    cout<<"Users: "<<"\n"<<user1.getName()<<" "<<user1.getSurname()<<", bank account number: "<<user1.bankaccount.size()<<"\n"<<user2.getName()<<" "<<user2.getSurname()<<", bank account number: "<<user2.bankaccount.size()<<"\n"<<user3.getName()<<" "<<user3.getSurname()<<", bank account number: "<<user1.bankaccount.size()<<endl;
    cout<<"Banks: "<<"\n"<<bank1.getName()<<"\n"<<bank2.getName()<<"\n"<<bank3.getName()<<endl;

    bool doing = true;
    while (doing) {
        cout << "Cosa vuoi fare? ricarica(0), transazione(1), prelievo(2), file transazioni conto(3), niente(4)" << endl;
        int a;
        cin >> a;
        switch (a) {
            case 0 : {
                cout << "Inserire ID intestatario"<< endl;
                int n;
                cin >> n;
                auto itu = users.find(n);
                cout<<"Quale dei "<<itu->second->bankaccount.size()<<" vuoi ricaricare? (partendo dallo 0)"<<endl;
                int num;
                cin>>num;
                cout << "quanto vuoi ricaricare?" << endl;
                float r;
                cin >> r;
                itu->second->bankaccount[num]->recharge(r);
                break;
            }
            case 1 : {
                cout << "Inserire ID del primo intestatario" << endl;
                int n;
                cin >> n;
                auto itu = users.find(n);
                cout<<"Quale dei "<<itu->second->bankaccount.size()<<" conti vuoi utilizzare? (partendo dallo 0)"<<endl;
                int num;
                cin>>num;

                cout << "Inserire ID del secondo intestatario" << endl;
                int p;
                cin >> p;
                auto itu2 = users.find(p);
                cout<<"Quale dei "<<itu2->second->bankaccount.size()<<" conti vuoi utilizzare? (partendo dallo 0)"<<endl;
                int num2;
                cin>>num2;

                cout << "Inserire importo della transazione, indicare se è in ingresso o uscita [i/u] e se vuole salvare la ricevuta su file [S/n]" << endl;
                float tr;
                string in;
                string esit;
                bool receiv;
                bool rec;
                cin >> tr;
                cin >> in;
                cin>>esit;
                if (in == "i")
                    rec = true;
               else if(in == "u")
                    rec = false;
               else
                   cout<<"Operazione non valida."<<endl;
               if(esit == "S")
                   receiv = true;
               else if(esit == "n")
                   receiv = false;

                itu->second->bankaccount[num]->transazione(rec, *(itu2->second->bankaccount[num2]), tr, receiv);
                break;
            }
            case 2 : {
                cout << "Inserire ID intestatario" << endl;
                int n;
                cin >> n;
                auto itu = users.find(n);
                cout<<"Da quale dei "<<itu->second->bankaccount.size()<<" conti vuoi prelevare? (partendo dallo 0)"<<endl;
                int num;
                cin>>num;
                cout << "Quanto vuoi prelevare?" << endl;
                float r;
                cin >> r;
                itu->second->bankaccount[num]->withdraw(r);
                break;
            }
            case 3 : {
                cout << "Inserire ID intestatario" << endl;
                int n;
                cin >> n;
                auto itu = users.find(n);
                cout<<"Di quale dei "<<itu->second->bankaccount.size()<<" conti vuoi ottenere la lista di transazioni? (partendo dallo 0)"<<endl;
                int num;
                cin>>num;
                itu->second->bankaccount[num]->fileTransaction();
            }
            case 4 : {
                doing = false;
                break;
            }
        }
    }

    cout<<"Vuoi un riepilogo delle transazioni salvate? [S/n]"<<endl;
    string risp;
    cin>>risp;
    if(risp == "S") {
        ifstream tfile;
        tfile.open("transazioni.txt");
        cout << endl;
        cout << "Lettura file transazioni.txt ..." << endl;
        cout << endl;

        string line;
        while (getline(tfile, line)) {
            cout << line << endl;
        }
        tfile.close();
    }


    return 0;
}



