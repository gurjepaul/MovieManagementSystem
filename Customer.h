/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Customer
Description:
    The purpose of this class is to represent a Customer that will contain
    basic information like an ID, first name and last name. This class is made
    so that a Customer is able to keep a transaction history of all the
    borrowing and returning of movies they have made.
------------------------------------------------------------------------------*/

#ifndef Customer_h
#define Customer_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;
class Customer
{
    
    friend ostream& operator<<(ostream &out, const Customer &cust);
    
public:
    Customer();
    Customer(int customerId, string firstName, string lastName);
    ~Customer();
    
    bool addTransaction(Transaction *t);
    
    //Setters
    bool setData(ifstream &file);
    bool setId(int cusId);
    void setLastName(string lastN);
    void setFirstName(string firstN);
    
    //Getters
    int getId()const;
    string getLastName()const;
    string getFirstName()const;
    
    //Operator Overloads
    Customer& operator=(const Customer& c);
    bool operator==(const Customer& cust)const;
    bool operator!=(const Customer& cust)const;
    
    bool returnIsValid(char movieType, Transaction const *borrowing)const;
    bool borrowIsValid(char movieType, Transaction const *returning) const;
    void viewHistory(); //Displays the customer's transaction history
    
private:
    int id;
    string lastName;
    string firstName;
    vector<Transaction*> history;
};

#endif /* Customer_h */
