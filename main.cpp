using namespace std;

#include <iostream>
#include <string>
#include "Bank.h"
#include "User.h"
#include "algorithm"
#include "memory"
#include "exception"
#include "stdexcept"

int Bank::bankAccountNumber = 0;



int main() {
    map<int, shared_ptr<User>> users;
    map<string, shared_ptr<Bank>> banks;
    map<int, shared_ptr<BankAccount>> bankaccounts;

    int iduser = 0;

    shared_ptr<User> user1 = make_shared <User>("Paul", "James", "455589049", "21st Avenue");
    iduser++;
    users.insert(make_pair(iduser, user1));
    shared_ptr<User> user2 = make_shared <User>("Anna", "Lawry", "7768357509", "Fulton Street");
    iduser++;
    users.insert(make_pair(iduser, user2));
    shared_ptr<User> user3 = make_shared <User>("Larry", "Howard", "3351705576", "Libbey Avenue");
    iduser++;
    users.insert(make_pair(iduser, user3));

    cout<<"Users: "<<"\n"<<user1->getName()<<" "<<user1->getSurname()<<"\n"<<user2->getName()<<" "<<user2->getSurname()<<"\n"<<user3->getName()<<" "<<user3->getSurname()<<endl;

    shared_ptr<Bank> bank1 = make_shared<Bank>("AmericanExpress", "3334445565", "New York");
    banks.insert(make_pair(bank1->getName(), bank1));
    shared_ptr<Bank> bank2 = make_shared<Bank>("HSBC", "441226261010", "London, UK");
    banks.insert(make_pair(bank2->getName(), bank2));
    shared_ptr<Bank> bank3 = make_shared<Bank>("Fineco", "4449574839", "Roma");
    banks.insert(make_pair(bank3->getName(), bank3));



    BankAccount bA1 = bank1->newBankAccount(*user1, 500);
    bankaccounts.insert(make_pair(bA1.getBankAccountNumber(), &bA1));
    BankAccount bA2 = bank1->newBankAccount(*user2, 500);
    bankaccounts.insert(make_pair(bA2.getBankAccountNumber(), &bA2));
    BankAccount bA3 = bank2->newBankAccount(*user3, 500);
    bankaccounts.insert(make_pair(bA3.getBankAccountNumber(), &bA3));
    BankAccount bA4 = bank2->newBankAccount(*user1, 500);
    bankaccounts.insert(make_pair(bA4.getBankAccountNumber(), &bA4));
    BankAccount bA5 = bank3->newBankAccount(*user1, 500);
    bankaccounts.insert(make_pair(bA5.getBankAccountNumber(), &bA5));
    BankAccount bA6 = bank3->newBankAccount(*user2, 500);
    bankaccounts.insert(make_pair(bA6.getBankAccountNumber(), &bA6));

    cout<<"Users: "<<"\n"<<user1->getName()<<" "<<user1->getSurname()<<", bank account number: "<<user1->bankAccountVectorSize()<<"\n"<<user2->getName()<<" "<<user2->getSurname()<<", bank account number: "<<user2->bankAccountVectorSize()<<"\n"<<user3->getName()<<" "<<user3->getSurname()<<", bank account number: "<<user3->bankAccountVectorSize()<<endl;
    cout<<"Banks: "<<"\n"<<bank1->getName()<<"\n"<<bank2->getName()<<"\n"<<bank3->getName()<<endl;

    bool doing = true;
    while (doing) {
        cout << "Cosa vuoi fare? ricarica(0), nuovaTransazione(1), prelievo(2), file transazioni conto(3), niente(4)" << endl;
        int a;
        cin >> a;
        switch (a) {
            case 0 : {
                try {
                    cout << "Inserire ID intestatario" << endl;
                    int n;
                    int i = users.size();
                    cin >> n;
                    if (n > (i) || n <= 0)
                        throw std::out_of_range("ID  inesistente.");
                    auto itu = users.find(n);
                    cout << "Quale dei " << itu->second->bankAccountVectorSize()
                         << " vuoi ricaricare? (partendo dallo 0)" << endl;
                    int num;
                    cin >> num;
                    auto bA = itu->second->findBankAccount(num);
                    cout << "quanto vuoi ricaricare?" << endl;
                    float r;
                    cin >> r;
                    bA->recharge(r);
                } catch (std::out_of_range& e){
                    cerr<<e.what()<<" Operazione annullata."<<endl;
                }
                break;
            }
            case 1 : {
                try {
                    cout << "Inserire ID del primo intestatario" << endl;
                    int n;
                    int i = users.size();
                    cin >> n;
                    if (n > (i) || n <= 0)
                        throw out_of_range("ID inesistente.");
                    auto itu = users.find(n);
                    cout << "Quale dei " << itu->second->bankAccountVectorSize()
                         << " conti vuoi utilizzare? (partendo dallo 0)" << endl;
                    int num;
                    cin >> num;
                    auto bA = itu->second->findBankAccount(num);
                    cout << "Inserire ID del secondo intestatario" << endl;
                    int p;
                    cin >> p;
                    if (p > (i) || p <= 0)
                        throw out_of_range("ID inesistente.");
                    auto itu2 = users.find(p);
                    cout << "Quale dei " << itu2->second->bankAccountVectorSize()
                         << " conti vuoi utilizzare? (partendo dallo 0)" << endl;
                    int num2;
                    cin >> num2;
                    auto bA2 = itu2->second->findBankAccount(num2);

                    cout<< "Inserire importo della transazione, indicare se è in ingresso o uscita [i/u] e se vuole salvare la ricevuta su file [S/n]"<< endl;
                    float tr;
                    string in;
                    string esit;
                    bool receiv;
                    bool rec;
                    cin >> tr;
                    cin >> in;
                    cin >> esit;
                    if (in == "i")
                        rec = true;
                    else if (in == "u")
                        rec = false;
                    else
                        cerr << "Operazione non valida." << endl;
                    if (esit == "S")
                        receiv = true;
                    else if (esit == "n")
                        receiv = false;

                    bA->nuovaTransazione(rec, *bA2, tr, receiv);
                }catch (out_of_range& e){
                    cerr<<e.what()<<"Operazione annullata."<<endl;
                }

                break;
            }
            case 2 : {
                try {
                    cout << "Inserire ID intestatario" << endl;
                    int i = users.size();
                    int n;
                    cin >> n;
                    if (n > (i) || n <= 0)
                        throw out_of_range("ID inesistente.");
                    auto itu = users.find(n);
                    cout << "Da quale dei " << itu->second->bankAccountVectorSize() << " conti vuoi prelevare? (partendo dallo 0)"
                         << endl;
                    int num;
                    cin >> num;
                    auto bA = itu->second->findBankAccount(num);
                    cout << "Quanto vuoi prelevare?" << endl;
                    float r;
                    cin >> r;
                    bA->withdraw(r);
                }catch (out_of_range& e){
                    cerr<<e.what()<<"Operazione annullata."<<endl;
                }
                break;
            }
            case 3 : {
                try {
                    cout << "Inserire ID intestatario" << endl;
                    int i = users.size();
                    int n;
                    if (n > (i) || n <= 0)
                        throw out_of_range("ID inesistente, riprovare.");
                    auto itu = users.find(n);
                    cout << "Di quale dei " << itu->second->bankAccountVectorSize()
                         << " conti vuoi ottenere la lista di transazioni? (partendo dallo 0)" << endl;
                    int num;
                    auto bA = itu->second->findBankAccount(num);
                    bA->loadTransactions();
                }catch (out_of_range& e){
                    cout<<e.what()<<" Operazione annullata."<<endl;
                }
                break;
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



