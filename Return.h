/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Return
Description:
    The Return class represents the Return transaction for a customer. This
    class is derived from the superclass Transaction, and overrides certain
    methods like doTrans() and display() based on the functionality of
    this class.
------------------------------------------------------------------------------*/

#ifndef Return_h
#define Return_h

#include "Transaction.h"

using namespace std;

class Return : public Transaction
{
public:
    //Constructors
    Return();
    Return(int customerID, Movie *movie);
    ~Return();
    
    void doTrans();
    void display()const;
};
#endif /* Return_h */
