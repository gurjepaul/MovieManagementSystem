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

#include <stdio.h>
#include "Customer.h"

/*---------------------------------Customer----------------------------------
Customer:
    This is a basic constructor that is called when a new Customer
    object is created.
----------------------------------------------------------------------------*/
Customer::Customer()
{

}

/*---------------------------------Customer----------------------------------
Customer:
    This is a basic constructor that takes in the information for a customer
    to be stored in the business's list of customers.
 
    Pre-Condition:
    int customerID - Represents the id number for the customer.
    string firstName - Represents the first name of the customer.
    string lastName - Representst the last name of the customer.
 
    Post Condition:
----------------------------------------------------------------------------*/
Customer::Customer(int customerID, string firstName, string lastName)
{
    setId(customerID);
    setFirstName(firstName);
    setLastName(lastName);
}

/*---------------------------------~Customer---------------------------------
~Customer:
    This represents a basic destructor.
----------------------------------------------------------------------------*/
Customer::~Customer()
{
    
}

/*---------------------------------setData-----------------------------------
setData:
    This method is a setter method that takes in the ifstream file and
    calls setter methods of the class to establish the variables for
    the customer.
 
    Pre-Condition:
    ifstream &file - Representst the file that we are going to read from
 
    Post Condition:
    The data from the ifstream file is set into the setters of the class
----------------------------------------------------------------------------*/
bool Customer::setData(ifstream &file)
{
    int id;
    string firstN, lastN;
    
    //Reads from the individual line in the file
    file >> id >> lastN >> firstN;
    
    //Checks to see if the id is valid
    if(setId(id) != true)
    {
        return false;
    }
    
    //If the id is valid, the rest of the information is stored
    setLastName(lastN);
    setFirstName(firstN);
    
    return true;
    
}

/*---------------------------------setId-------------------------------------
 setId:
    A basic setter that sets the id of the customer.
 
    Pre-Condition:
    int cusId - Represents the id of the customer.
 
    Post Condition:
    The current customer object now has an id that indentify it.
----------------------------------------------------------------------------*/
bool Customer::setId(int cusId)
{
    //ID must be in between 999-10000
    //for it to be valid
    if(cusId > 999 && cusId < 10000)
    {
        this->id = cusId;
        return true;
    }
    
    //Returns false and alerts the store if the id is invalid
    cerr << "ERROR: Invalid ID " << cusId << ". Customer not created" << endl;
    return false;
}

/*--------------------------------setLastName--------------------------------
 setLastName:
    A basic setter that sets the last name of the customer.
 
    Pre-Condition:
    string lastN - Represents the last name of the customer.
 
    Post Condition:
    The current customer object now has a last name.
----------------------------------------------------------------------------*/
void Customer::setLastName(string lastN)
{
    this->lastName = lastN;
}

/*--------------------------------setFirstName-------------------------------
 setFirstName:
    A basic setter that sets the first name of the customer.
 
    Pre-Condition:
    string firstN - Represents the first name of the customer.
 
    Post Condition:
    The current customer object now has a first name.
----------------------------------------------------------------------------*/
void Customer::setFirstName(string firstN)
{
    this->firstName = firstN;
}

/*---------------------------------getId-------------------------------------
getId:
    This is a basic getter that returns the customer's id.
----------------------------------------------------------------------------*/
int Customer::getId()const
{
    return this->id;
}

/*---------------------------------getLastName-------------------------------
 getLastName:
    This is a basic getter that returns the customer's last name.
----------------------------------------------------------------------------*/
string Customer::getLastName()const
{
    return this->lastName;
}

/*---------------------------------getFirstName------------------------------
 getFirstName:
    This is a basic getter that returns the customer's first name.
----------------------------------------------------------------------------*/
string Customer::getFirstName()const
{
    return this->firstName;
}

/*---------------------------------addTransaction----------------------------
addTransaction:
    This method adds a transaction object to the customers list of transactions
    in the history variable.
 
    Pre-Condition:
    Transaction *t - Represents the transaction that we want to insert into
                    our history of transactions
    
    Post Condition:
    A new transaction object is inserted into the history of transactions
    for the customer.
 
----------------------------------------------------------------------------*/
bool Customer::addTransaction(Transaction *t)
{
    //Adds a transaction object to the customers transaction history
    history.push_back(t);
    
    return true;
}

/*---------------------------------operator=---------------------------------
operator=:
    This is a = overloaded operator which assigns another customers information
    to the current customer (this customer).
    Pre-Condition:
    Customer &c - Represents another customer that we want to copy
    
    Post Condition:
    Returns a Customer reference and creates copy of the passed in customer
----------------------------------------------------------------------------*/
Customer& Customer::operator=(const Customer &c)
{
    //If the right handed side is a default Customer object
    if(c.getFirstName() == "" && c.getLastName() == "" && c.getId() == -1)
    {
        //then just return the current Customer
        return *this;
    }
    
    //Otherwise, set the information from the right side to the current Customer
    setFirstName(c.getFirstName());
    setLastName(c.getLastName());
    setId(c.getId());
    
    return *this;
}

/*----------------------------------operator==------------------------------
operator==:
    This is a == overloaded operator which checks for equality of another
    customer object.
 
    Pre-Condition:
    Customer &cust - Represents the customer that we want to compare to
       
    Post Condition:
    Returns true or false whether the current customer and the other
    customer are equal to each other
----------------------------------------------------------------------------*/
bool Customer::operator==(const Customer &cust)const
{
    //If both IDs are the same
    if(this->getId() == cust.getId()){
        //If both last names are the same
        if(this->getLastName().compare(cust.getLastName()) == 0){
            //If both first names are the same
            if(this->getFirstName().compare(cust.getFirstName()) == 0){
                //Then both Customer objects are equal
                return true;
            }
        }
    }
    
    //Return false if any of the conditions above are not true
    return false;
}

/*--------------------------------operator!=---------------------------------
operator!=:
    Just makes use of the == operator by returning the opposite of it
----------------------------------------------------------------------------*/
bool Customer::operator!=(const Customer &cust)const
{
    return !(*this == cust);
}

/*-------------------------------returnIsValid--------------------------------
returnIsValid:
    This method is used to to check and see if the customer is able to return
    a certain movie by going through the history of transactions and
    checking each transaction to see if the number of returns will equal
    the number of borrowed movies.
 
    Pre-Condition:
    char movieType - Represents the type of movie that the customer wants to
                     check if they've returned the movie
    Transaction *borrowing - Represents the transaction that contains the
                             movie that was borrowed
 
    Post Condition:
    Returns whether or not the customer is able to return the movie or whether
    they are not able to return the movie cause they never borrowed it
----------------------------------------------------------------------------*/
bool Customer::returnIsValid(char movieType, Transaction const *borrowing) const
{
    // Get the movie selection
    Movie *selection = borrowing->getMovie();
    
    int numBorrowed = 0;
    int numReturned = 0;
    
    // Loop through this customers history of transactions
    for (int i = 0; i < history.size(); i++)
    {
        if(movieType == selection->getMovieType())
        {
            // If we find a transaction with their selected movie
            if (history[i]->getMovie() == selection)
            {
                // If the transaction was a borrow
                if (history[i]->getTransactionType() == 'B')
                {
                    numBorrowed++;
                }
                // If the transaction was a return
                else if (history[i]->getTransactionType() == 'R')
                {
                    numReturned++;
                }
            }
        }
    }
    
    // the customer can return it if they borrowed it
    if ((numReturned + 1) == numBorrowed)
    {
        return true;
    }
    
    cerr << "ERROR: The selected movie cannot be returned" << endl;
    return false;
}

/*------------------------------borrowIsValid-------------------------------
 borrowIsValid:
    
    This method is used to to check and see if the customer is able to borrow
    a certain movie by going through the history of transactions and
    checking each transaction to see if the number of borrows will equal
    the number of returned movies.
 
    Pre-Condition:
    char movieType - Represents the type of movie that the customer wants to
                     check if they can borrow
    Transaction *returning - Represents the transaction that contains the
                             movie that was returned
 
    Post Condition:
    Returns whether or not the customer is able to borrow the movie or whether
    they are not able to borrow the movie cause they never returned it
----------------------------------------------------------------------------*/
bool Customer::borrowIsValid(char movieType, Transaction const *returning) const
{
    // Get the movie selection
    Movie *selection = returning->getMovie();
    
    int numBorrowed = 0;
    int numReturned = 0;
    
    // If we find a transaction with their selected movie
    for (int i = 0; i < history.size(); i++)
    {
        if(movieType == selection->getMovieType())
        {
            // If we find a transaction with their selected movie
            if (history[i]->getMovie() == selection)
            {
                // If the transaction was a borrow
                if (history[i]->getTransactionType() == 'B')
                {
                    numBorrowed++;
                }
                // If the transaction was a return
                else if (history[i]->getTransactionType() == 'R')
                {
                    numReturned++;
                }
            }
        }
    }
    
    // the customer can borrow since they don't have it borrowed right now
    if (numBorrowed == numReturned)
    {
        return true;
    }
    
    cerr << "ERROR: The selected movie cannot be borrowed" << endl;\
    return false;
}

/*-------------------------------viewHistory--------------------------------
viewHistory:
    This method prints out the customers Transaction history from their
    transaction vector.
----------------------------------------------------------------------------*/
void Customer::viewHistory()
{
    cout << "Customer " << this->id << " Transaction History (Earliest to Latest):" << endl;
    
    if (history.size() == 0)
    {
        cout << " NO HISTORY" << endl;
        cout << endl;
    }
    else
    {
    //Outputting all the Transaction objects in the history vector
    for(int i = 0; i < history.size(); i++)
    {
        history[i]->display();
    }
    cout << endl;
    }
}

/*-----------------------------operator<<------------------------------------
operator<<:
    This is a basic ostream overload that prints out the customers details.
----------------------------------------------------------------------------*/
ostream& operator<<(ostream &out, const Customer &cust)
{
    out << "Customer ID " << cust.getId() << ": "
    << cust.getFirstName() << " " << cust.getLastName() << endl;
    
    return out;
}
