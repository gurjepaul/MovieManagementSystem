/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Transaction
Description:
    This class represents the basic functionalities, and variables that a
    transaction object will contain. This is also intended to be the superclass
    to the subclasses Borrow and Return. With this transaction class, we are
    able to store what kind of transaction a customer has made in the business.
    The transaction object also contains all the details of the movie, and
    all the customer's details.
------------------------------------------------------------------------------*/

#ifndef Transaction_h
#define Transaction_h

#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

class Transaction
{
public:
    //Constructors
    Transaction();
    Transaction(char transactionType, int customerID, Movie *movie);
    ~Transaction();
    
    //Setters
    virtual void setCustomerID(int customerID);
    virtual void setTransactionType(char type);
    virtual void setMovie(Movie *movie);
    
    //Getters
    virtual int getCustomerID()const;
    virtual char getTransactionType()const;
    virtual Movie* getMovie()const;
    
    virtual void doTrans(); //Method that executes the transaction
    virtual void display()const; //Method that displays the transaction
    
protected:
    int customerID;
    Movie *movie;
    char transactionType;
};

#endif /* Transaction_h */
