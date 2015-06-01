//
//  BookStore.h
//  BookStore
//  Description Header File of BookStore
//  Created by Swasti Gupta on 5/31/15.
//
//

#ifndef __BookStore__BookStore__
#define __BookStore__BookStore__

#include "Book.h"
#include "GBookStore.h"
#include "Transaction.h"
#include "Customer.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include "Base.h" 

/*
 Declaring BookStore Class Components with the STL
*/
class BookStore :public ABookStore
{ 
private:
    map <string,Book> mBookMap; // a map for storing Book Information
    
	vector <Transaction> mTransactionList; // a vector for storing transactions 
											//Information
    map <string,Customer> mCustomerMap; //a map for storing Customer Information
   
	// to compare values frist based on secound key values then first key values
	static bool compare(pair<string,int>&obj1, pair<string,int>&obj2);

    struct less_than_key; // a structure having comparison fuction for 
						//different class objects

	GStatus findNTopTrans(int n); // prints top n transaction based on
									//total transaction value.

    GStatus findNfrequentCus(int n); // prints top n customers based on visits

    GStatus findNBooks(int n); // prints n values of books from top as
								//well as bottom based on sales.
public:
    GStatus readPriceList(char *filename); // reads priceList
	
	GStatus readTransactionList (char* filename); // reads transactionList
    
	GStatus getNValues(int n); // calls private functions
    
	GStatus isDiscount(char* custId, double, int* ); // checks if given customer is
										//eligible for discount
};
#endif /* defined(__BookStore__BookStore__) */
