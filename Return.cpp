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

#include <stdio.h>
#include "Return.h"

/*-----------------------------------Return-----------------------------------
 Return:
    A basic constructor that sets the Transaction type to R.
 Post Condition:
    Sets the transaction type for Borrow as R and a Return object is created.
----------------------------------------------------------------------------*/
Return::Return()
{
    setTransactionType('R');
}

/*----------------------------------Return------------------------------------
 Return:
    A basic constructor that sets the values from the parameters to the
    private variables of the class.
 Pre-Conditions:
    int customerID - Represents the customer that the transaction belongs to
    Movie *movie - Represents the movie that is being returned
 Post Conditions:
    The instance variables are assigned to the parameters passed in
    and a new Return transaction object is created
----------------------------------------------------------------------------*/
Return::Return(int customerID, Movie *movie)
{
    setTransactionType('R');
    setCustomerID(customerID);
    setMovie(movie);
}

/*---------------------------------~Return------------------------------------
 ~Return:
    A basic destructor that sets the Movie variable to null
    Post Condition:
    The movie in Return is set to null
----------------------------------------------------------------------------*/
Return::~Return()
{
    this->movie = nullptr;
}

/*-----------------------------------doTrans---------------------------------
 doTrans:
    This method increases the stock of the movie in the transaction.
 Post Condition:
    The movie that is being returned increases in stock.
----------------------------------------------------------------------------*/
void Return::doTrans()
{
    this->movie->increaseStock();
}

/*----------------------------------display----------------------------------
 display:
    Method that displays the borrowed movie and the details that come with it.
----------------------------------------------------------------------------*/
void Return::display()const
{
    cout << "Returned: ";
    //If the movie type for the return object is C
    //then we must print out the details for the Classic movie
    if(this->movie->getMovieType() == 'C')
    {
        cout << this->movie->getMovieType() << ", " << this->movie->getDirector() << ", "
        << this->movie->getTitle() << ", " << this->movie->getMajorActor() << " "
        << this->movie->getReleaseMonth() << " " << this->movie->getReleaseYear() << endl;
    }
    //Else if the movie type for the return object is F
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
