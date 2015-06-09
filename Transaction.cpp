//
//  Transaction.cpp
//  Transaction
//  Description CPP file of Transaction Class
//  Created by Swasti Gupta on 5/31/15.
//
//

#include "Transaction.h"

/*
 Description constructor of Transaction Class
 */
Transaction::Transaction()
{
    mTransactionAmnt = 0;
    mCustomerId = "";
}

/*
 param bookId to be added
 Description add Book to purchased book List
 */
void Transaction::addBook(string bookId)
{
    mPurchasedBookList.push_back(bookId);
}

/*
 Description returns the purchased book list
 */
list<string>& Transaction::getPurchasedBookList() 
{
        return mPurchasedBookList;
}

/*
 param total transction amount
 Description sets the transaction amount
 */
void Transaction::setTransactionAmnt(double sum)
{
    mTransactionAmnt = sum;
}

/*
 Description returns the total transaction amount
 */
double Transaction::getSum()
{
    return mTransactionAmnt;
}

/*
 param customerId to be set
 Description sets the customerId of purchaser
 */
void Transaction::setCustomerId(string custId)
{
    mCustomerId = custId;
}

/*
 Description returns the customerId of the purchaser
 */
string Transaction:: getCustomerId()
{
    return mCustomerId;
}

/*
 param object of transaction type to be compared
 param customerId to be compared
 Description compares the customerId of 
             the transactions object with the given customerId
 */
bool operator == (Transaction obj, string custId){
    return (obj.mCustomerId.compare(custId) == 0);
}
