/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Borrow
Description:
    The Borrow class represents the Borrow transaction for a customer. This
    class is derived from the superclass Transaction, and overrides certain
    methods like doTrans() and display() based on the functionality of
    this class.
------------------------------------------------------------------------------*/

#ifndef Borrow_h
#define Borrow_h

#include "Transaction.h"

using namespace std;

class Borrow : public Transaction
{
public:
    //Constructors
    Borrow();
    Borrow(int customerID, Movie *movie);
    ~Borrow();
    
    void doTrans();
    void display()const;
};
#endif /* Borrow_h */
