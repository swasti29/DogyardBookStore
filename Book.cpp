//
//  Book.cpp
//  Book
//  Description Cpp File of Book Class
//  Created by Swasti Gupta on 5/31/15.
//
//

#include "Book.h"

/*
 Description Book Class Constructor
*/
Book::Book()
{
    mPrice = 0;
	mName.assign("");
}

/*
 Param : price of Book
 Param : name of Book
 Description Book Class Constructor
*/
Book :: Book(double price, string name)
{
    mPrice = price;
	mName.assign(name);
}

/*
 Description returns price of Book
*/
double Book::getPrice()
{
    return mPrice;
}

/*
 Param price of book to be set
 Description sets price of book
*/
void Book::setPrice(double price)
{
    mPrice = price;
}

/*
 Description returns name of book
*/
string Book::getName()
{
    return mName;
}

/*
 Description sets name of customer
*/
void Book::setName (string name)
{
	mName.assign(name);
}