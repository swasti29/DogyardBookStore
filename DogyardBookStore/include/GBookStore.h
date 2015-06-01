//
//  GBookStore.h
//  GBookStore
//  Description Header File of GBookStore
//  Created by Swasti Gupta on 5/31/15.
//
//
#include "Book.h"
#include "Transaction.h"
#include "Customer.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include "Base.h" 

#ifndef __ABookStore__ABookStore__
#define __ABookStore__ABookStore__
/*
 Declaring an Interface class for BookStore so that any library
 can be used for the implementation of functions of Book Store
 (Here using STL)
*/
class ABookStore
{    
public:
    virtual GStatus readPriceList(char* filename) = 0; 
    virtual GStatus readTransactionList (char* filename) = 0;
    virtual GStatus getNValues(int n) = 0;
	virtual GStatus isDiscount(char* custId, double, int* ) = 0;
};
#endif /* defined(__GBookStore__GBookStore__) */

#ifndef __GBookStore__GBookStore__
#define __GBookStore__GBookStore__

/*
 Declaring  Wrapper Class for Book Store Class to enable 
 interaction with other classes or interfaces  
*/
class GBookStore
{
private:
	ABookStore *mABookStore; // pointer to Abstract class used to store address of child class
public:
	GBookStore(); // constructor of GStoreClass
	~GBookStore(); // destructor of GStoreClass
    GStatus readPriceList(char* filename); //calls child class readPriceList
    GStatus readTransactionList (char* filename);// calls child class 
													//readTrasactionList
    GStatus getNValues(int n); //calls child class getNValues
	GStatus isDiscount(char* custId, double, int* ); //calls child class isDiscount
};
#endif /* defined(__GBookStore__GBookStore__) */
