//
//  Book.h
//  Book
//  Description Header file for Class Book
//  Created by Swasti Gupta on 5/31/15.
//
//

#ifndef __Book__Book__
#define __Book__Book__

#include <iostream>
#include <string>
using namespace std;

/*
 Declaring Book Class Components
*/
class Book
{
private:
    double mPrice; // price of Book
    string mName;  // name of Book
public:
    Book(); // Constructor of Book class

    Book(double price,string name); //Contructor of Book class for intializing 
									//components.
    
	double getPrice(); // return the price of book
    
	void setPrice(double price); //sets the price of book
    
	string getName(); // returns the name of book
    
	void setName (string name); //sets the name of book
};
#endif /* defined(__Book__Book__) */
