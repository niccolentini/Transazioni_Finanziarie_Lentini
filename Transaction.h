//
// Created by nicco on 27/07/21.
//

#ifndef TRANSAZIONIFINANZIARIE_TRANSACTION_H
#define TRANSAZIONIFINANZIARIE_TRANSACTION_H
using namespace std;
#include "string"
#include "stdexcept"

class Transaction {
public:
    Transaction(int s, int r, float a, string d, bool re){
        if(s != r && a > 0) {
            sender = s;
            receiver = r;
            amount = a;
            data = d;
            received = re;
        }
        else {
            throw invalid_argument("Valori non validi per la creazione di una transazione.");
        }
    }

    int getSender() const {
        return sender;
    }
    int getReceiver() const {
        return receiver;
    }
    float getAmount() const {
        return amount;
    }
    const string &getData() const {
        return data;
    }

private:
    int sender;
    int receiver;
    float amount;
    string data;
    bool received;
};



#endif //TRANSAZIONIFINANZIARIE_TRANSACTION_H
