//
//  Transaction.h
//  Transaction
//  Description Header File for Transaction
//  Created by Swasti Gupta on 5/31/15.
//
//

#ifndef __Transaction__Transaction__
#define __Transaction__Transaction__

#include <list>
#include <string>
using namespace std;

/*
 Declaring Transation Class Components
*/
class Transaction
{
private:
    double mTransactionAmnt; // total Transaction Amount
    list<string> mPurchasedBookList; // list of books purchased
    string mCustomerId; // customerId of purchaser
public:
    Transaction(); // constructor of Transaction
    void addBook(string bookId); // add Book to purchased book list.
    list<string>& getPurchasedBookList(); // return purchased book list
    void setTransactionAmnt(double sum); // sets total transaction amount.
    double getSum(); // returns total transaction amount.
    void setCustomerId (string custId); // sets customerId of purchaser.
    string getCustomerId(); // returns customerId of purchaser.
    friend bool operator == (Transaction, string); // friend function to compare 
												//two objects of Transaction class
};
#endif /* defined(__Transaction__Transaction__) */
