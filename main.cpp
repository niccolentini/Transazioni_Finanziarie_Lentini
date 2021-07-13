using namespace std;

#include <iostream>
#include "string"
#include "BankAccount.h"

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

int main() {


    return 0;
}
