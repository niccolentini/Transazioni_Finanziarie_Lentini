using namespace std;

#include <iostream>
#include "string"
#include "Bank.h"
#include "User.h"

int Bank::bankAccountNumber = 0;

int main() {
    User user1 ("Paul", "James", "455589049", "21st Avenue");
    User user2("Anna", "Lawry", "7768357509", "Fulton Street");
    User user3("Larry", "Howard", "3351705576", "Libbey Avenue");

    Bank bank1("American Express", "3334445565", "New York");
    Bank bank2("HSBC Bank", "44 1226 261010", "London, UK");

    BankAccount bA1 = bank1.newBankAccount(user1);
    BankAccount bA2 = bank1.newBankAccount(user2);
    BankAccount bA3 = bank2.newBankAccount(user3);

    bA1.recharge(1000);
    bA2.recharge(3600);
    bA3.recharge(2456.68);

    bA2.transazione(true, bA1, 500);
    bA2.info();
    cout<<endl;
    bA1.info();
    cout<<endl;

    bA3.transazione(false, bA1, 400.50);
    bA3.info();
    cout<<endl;
    bA1.info();



    return 0;
}
