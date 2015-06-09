//
//  Test.cpp
//  Test CPP file of main function
//  Description : Main function Implementation
//  Created by Swasti Gupta on 5/31/15.

#include "GBookStore.h"
#include "Base.h"
#include "CmdLineParser.h"
#include <sstream>

/*
 Description Main function
 */
int main(int argc, const char * argv[])
{
	if(argc != 7 && argc != 9)
	{
		return GParamError;
	}
	GStatus status;
	CmdLineParser cmdParse; //Parser for Command Line Arguments

	//checking for option t exits otherwise return parameter error
	if(!cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "t"))
    {
        return GParamError;
    }

	//checking for option p exits otherwise return parameter error
	if(!cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "p"))
    {
        return GParamError;
    }

	//checking for option r, d, c exits otherwise return parameter error
    if(!cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "r") && 
		(!cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "d") 
		||!cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "c") ))
    {
        return GParamError;
    }

	//getting the  TransactionList file path 
	char *fileTransaction = cmdParse.getCmdOption((char**)argv, (char**)argv + argc, "t");
	if( fileTransaction == NULL)
	{
		return GParamError;
	}
	//getting the  PriceList file path 
	char *filePrice = cmdParse.getCmdOption((char**)argv, (char**)argv + argc, "p");
	if( filePrice == NULL)
	{
		return GParamError;
	}

	GBookStore b;// Object of GStore
	if(cmdParse.cmdOptionExists((char**)argv, (char**)argv+argc, "r"))
	{
		//getting the value of N
		char *nValue = cmdParse.getCmdOption((char**)argv,(char**)argv + argc, "r");
		if( nValue == NULL)
		{
			return GParamError;
		}
		status = b.readPriceList(filePrice); //reading the priceList file.
		if(status != GSuccess)
		{
			return status;
		}

		status = b.readTransactionList(fileTransaction); //reading the transactionList file.
		if(status != GSuccess)
		{
			return status;
		}

		status = b.getNValues(atoi(nValue)); // getting top K Transation, top K Customers, top and bottom Books
		if(status != GSuccess)
		{
			return status;
		}
	}
	else
	{
		//getting the value of sum upto whic discount is given or not
		char *discountValue = cmdParse.getCmdOption((char**)argv,(char**)argv + argc, "d");
		if( discountValue == NULL || stod(discountValue) <= 0)
		{
			return GParamError;
		}
		//getting the CustmerId
		char *custId = cmdParse.getCmdOption((char**)argv,(char**)argv + argc, "c");
		if( custId == NULL || custId[0] != 'C')
		{
			return GParamError;
		}
		status = b.readPriceList(filePrice); //reading the priceList file.
		if(status != GSuccess)
		{
			return status;
		}

		status = b.readTransactionList(fileTransaction); //reading the transactionList file.
		if(status != GSuccess)
		{
			return status;
		}
		int discount = 0;
		//calculating the state of providing discount
		status = b.isDiscount(custId,stod(discountValue),&discount);
		if(status != GSuccess)
		{
			return status;
		}
		if(discount)
		{
			cout<<endl<<"1"<<endl;
		}
		else
		{
			cout<<endl<<"0"<<endl;
		}
	}
	return GSuccess;
}

