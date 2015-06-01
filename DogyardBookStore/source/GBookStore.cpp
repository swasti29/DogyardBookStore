//
//  GBookStore.cpp
//  GBookStore
//  Description CPP file of GBookStore
//  Created by Swasti Gupta on 5/31/15.
//
//

#include "GBookStore.h"
#include "BookStore.h"

/*
 Description GBookStore Class Constructor
*/
GBookStore :: GBookStore()
{
	//assing a child class address to pointer of type interface class ABookStore
	mABookStore = new BookStore();
}

/*
 Description GBookStore Class Destructor
*/
GBookStore ::~GBookStore()
{
	//check if pointer of interface class is already NULL otherwise deleting it
	if(mABookStore != NULL)
	{
		delete mABookStore;
	}
}

/*
 param  integer varialble upto which values to be printed
 Description calls the private functions for printing values
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus GBookStore ::getNValues(int n)
{
	if(mABookStore != NULL)
	{
		// calls the child class BookStore function
		return mABookStore->getNValues(n); 
	}
	return GFail;
}

/*
 param priceList file path
 Description reads the priceList
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus GBookStore ::readPriceList(char* filename)
{
	if(mABookStore != NULL)
	{
		// calls the child class BookStore function
		return mABookStore->readPriceList(filename);
	}
	return GFail;
}

/*
 param TransactionList file path
 Description reads the TransactionList file
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus GBookStore ::readTransactionList(char* filename)
{
	if(mABookStore != NULL)
	{
		// calls the child class BookStore function
		return mABookStore->readTransactionList(filename);
	}
	return GFail;
}

/*
 param customerId
 param base Value above which discount available
 param denotes the applicability of discount
 Description the applicability of discount
 Return returns the GStatus for Success otherwise GParaError for Parameter Error
 */
GStatus GBookStore ::isDiscount(char* custId, double value, int *discount)
{
	if(mABookStore != NULL)
	{
		// calls the child class BookStore function
		return mABookStore->isDiscount(custId,value,discount);
	}
	return GFail;
}