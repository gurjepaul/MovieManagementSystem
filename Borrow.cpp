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

#include <stdio.h>
#include "Borrow.h"

/*---------------------------------Borrow------------------------------------
Borrow:
    A basic constructor that sets the Transaction type to B.
Post Condition:
    Sets the transaction type for Borrow as B and a Borrow object is created.
----------------------------------------------------------------------------*/
Borrow::Borrow()
{
    setTransactionType('B');
}

/*---------------------------------Borrow------------------------------------
Borrow:
    A basic constructor that sets the values from the parameters to the
    private variables of the class.
Pre-Conditions:
    int customerID - Represents the customer that the transaction belongs to
    Movie *movie - Represents the movie that is being borrowed
Post Conditions:
    The instance variables are assigned to the parameters passed in
    and a new Borrow transaction object is created
----------------------------------------------------------------------------*/
Borrow::Borrow(int customerID, Movie *movie)
{
    setTransactionType('B');
    setCustomerID(customerID);
    setMovie(movie);
}

/*----------------------------------~Borrow----------------------------------
~Borrow:
    A basic destructor that sets the Movie variable to null
Post Condition:
    The movie in Borrow is set to null
----------------------------------------------------------------------------*/
Borrow::~Borrow()
{
    this->movie = nullptr;
}

/*----------------------------------doTrans-----------------------------------
doTrans:
    This method decreases the stock of the movie in the transaction.
Post Condition:
    The movie that is being borrowed decreases in stock.
----------------------------------------------------------------------------*/
void Borrow::doTrans()
{
    this->movie->decreaseStock();
}

/*-----------------------------------display----------------------------------
display:
    Method that displays the borrowed movie and the details that come with it.
----------------------------------------------------------------------------*/
void Borrow::display()const
{
    cout << "Borrowed: ";
    //If the movie type for the borrow object is C
    //then we must print out the details for the Classic movie
    if(this->movie->getMovieType() == 'C')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getMajorActor() << " "
        << this->movie->getReleaseMonth() << " " << this->movie->getReleaseYear() << endl;
    }
    //Else if the movie type for the borrow object is F
    //then we must print out the details for the Comedy movie
    else if(this->movie->getMovieType() == 'F')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getReleaseYear() << endl;
    }
    //If the other conditions never happened, then that means we have
    //a Drama movie left to print out the details
    else
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getReleaseYear() << endl;
    }
    
}
