using namespace std;

#include <iostream>
#include <string>
#include "Bank.h"
#include "User.h"
#include "algorithm"
#include <fstream>

int Bank::bankAccountNumber = 0;



int main() {
    map<string, User*> users;
    map<string, Bank*> banks;
    map<int, BankAccount*> bankaccounts;

    bool create = true;
    int i;

    while(create == true){
    cout<<"Cosa vuoi creare? user(0), bank(1), bank account(2), niente(3)"<<endl;
    cin>>i;
    switch(i) {
        case 0 : {
            cout << "Inserire: nome, cognome, numero di telefono e indirizzo del nuovo utente" << endl;
            string n, s, t, a;
            cin >> n;
            cin >> s;
            cin >> t;
            cin >> a;
            string k = n + " " + s;
            User u(n, s, t, a);
            users.insert(make_pair(k, &u));
            break;
        }
        case 1 : {
            cout << "Inserire: nome, numero di telefono e indirizzo della banca" << endl;
            string n, t, a;
            cin >> n;
            cin >> t;
            cin >> a;
            Bank b(n, t, a);
            banks.insert(make_pair(n, &b));
            break;
        }
        case 2 : {
            if (users.size() == 0 || banks.size() == 0) {
                cout << "Non è possibile creare un conto bancario senza utenti/banche" << endl;
                break;
            }

            cout << "Inserire nome della banca e utente intestatario del conto (nome e cognome)" << endl;
            string b, u;
            cin >> b;
            cin >> u;
            auto itb = banks.find(b);
            auto itu = users.find(u);

            if (itb == banks.end() || itu == users.end()) {   //fixme, non funziona find?? ne funziona uno solo??
                    cout << "Dati non validi" << endl;
            }
            else
                itb->second->newBankAccount(*(itu->second));

            break;
            }

        case 3 : {
            create = false;
            break;
        }
      }
    }

    //TODO: fare si che due user possano effettuare una transazione/ricaricare/prelevare (uso dereferenziazione dei ptr a bankaccount)
    //TODO: prima però devi ricaricare i bank account

    bool doing = true;
    while (doing) {
        cout << "Cosa vuoi fare? ricarica(0), transazione(1), prelievo(2), niente(3)" << endl;
        int a;
        cin >> a;
        switch (a) {
            case 0 : {
                cout << "Inserire nome intestatario e numero conto" << endl;
                string n;
                int num;
                cin >> n;
                cin >> num;
                auto itu = users.find(n);
                auto itc = find(*itu->second->bankaccount.begin(), *itu->second->bankaccount.end(), num);
                cout << "quanto vuoi ricaricare?" << endl;
                float r;
                cin >> r;
                itc->recharge(r);
                break;
            }
            case 1 : {
                cout << "Inserire nome del primo intestatario e numero conto" << endl;
                string n;
                int num;
                cin >> n;
                cin >> num;
                auto itu = users.find(n);
                auto itc = find(*itu->second->bankaccount.begin(), *itu->second->bankaccount.end(), num);

                cout << "Inserire nome del secondo intestatario e numero conto" << endl;
                string p;
                int num2;
                cin >> p;
                cin >> num2;
                auto itu2 = users.find(p);
                auto itc2 = find(*itu2->second->bankaccount.begin(), *itu2->second->bankaccount.end(), num2);

                cout << "Inserire importo della transazione e indicare se è in entrta o in uscita [E/u]" << endl;
                float tr;
                string in;
                bool rec;
                cin >> tr;
                cin >> in;
                if (in == "E")
                    rec = true;
                else
                    rec = false;

                itc->transazione(rec, *itc2, tr);
                break;
            }
            case 2 : {
                cout << "Inserire nome intestatario e numero conto" << endl;
                string n;
                int num;
                cin >> n;
                cin >> num;
                auto itu = users.find(n);
                auto itc = find(*itu->second->bankaccount.begin(), *itu->second->bankaccount.end(), num);
                cout << "Quanto vuoi prelevare?" << endl;
                float r;
                cin >> r;
                itc->withdraw(r);
                break;
            }
            case 3 : {
                doing = false;
                break;
            }
        }
    }

// TODO: lettura e scrittura su file. scrivere una ricevuta di transazione. leggere dati di un account utente...

    /* User user1 ("Paul", "James", "455589049", "21st Avenue");
    User user2("Anna", "Lawry", "7768357509", "Fulton Street");
    User user3("Larry", "Howard", "3351705576", "Libbey Avenue");

    ofstream PaulJames;
    PaulJames.open("paulj.txt");

    PaulJames<<"User: Paul James "<<user1.getTelephoneNumber()<<" \n"<<endl;

    Bank bank1("American Express", "3334445565", "New York");
    Bank bank2("HSBC Bank", "44 1226 261010", "London, UK");

    BankAccount bA1 = bank1.newBankAccount(user1);
    BankAccount bA2 = bank1.newBankAccount(user2);
    BankAccount bA3 = bank2.newBankAccount(user3);

    bA1.recharge(1000);
    bA2.recharge(3600);
    bA3.recharge(2456.68);

    PaulJames<<"Balance of "<<user1.getName()<<" "<<user1.getSurname()<<" = "<<bA1.getBalance()<<"\n"<<endl;

    bA2.transazione(true, bA1, 500);
    bA2.info();
    cout<<endl;
    bA1.info();
    cout<<endl;

    bA3.transazione(false, bA1, 400.50);
    bA3.info();
    cout<<endl;
    bA1.info();

    PaulJames<<"New Balance= "<<bA1.getBalance()<<"\n";
    PaulJames.close();

    ifstream PaulJ;
    PaulJ.open("paulj.txt");
    cout<<"Lettura file paulj.txt"<<endl;

    string line;
    while( getline (PaulJ, line)){
        cout<<line<<endl;
    }

    PaulJ.close();
*/
    return 0;
}
