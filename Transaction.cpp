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

  #include <stdio.h>
  #include "Transaction.h"

  /*----------------------------Transaction-----------------------------------
  Transaction:
      A basic constructor that creates a Transaction object and sets the
      customerID to -1 as default.
   
      Post Condition:
      Sets the customer id to a default -1.
  ----------------------------------------------------------------------------*/
  Transaction::Transaction()
  {
      setCustomerID(-1);
  }

  /*----------------------------~Transaction-----------------------------------
  ~Transaction:
      A basic destructor that sets the Movie variable to null.
      Post Condition:
      The movie in Transaction is set to null
  ----------------------------------------------------------------------------*/
  Transaction::~Transaction()
  {
      movie = nullptr;
  }

  /*-----------------------------Transaction-----------------------------------
  Transaction:
      A basic constructor that sets the values from the parameters to the
      private variables of the class.
  Pre-Conditions:
      char transactionType - Represents the type of transaction for the object
      int customerID - Represents the customer that the transaction belongs to
      Movie *movie - Represents the movie that is being returned
  Post Conditions:
      The instance variables are assigned to the parameters passed in
      and a new Transaction object is created
  ----------------------------------------------------------------------------*/
  Transaction::Transaction(char transactionType, int customerID, Movie *selection)
  {
      setTransactionType(transactionType);
      setCustomerID(customerID);
      setMovie(selection);
  }

  /*------------------------------setCustomerID--------------------------------
  setCustomerID:
      This is a basic setter that sets the customerID for the transaction
      to the customerID being passed in when the object is created.
  Pre-Condition:
      int customerID - Represents the customerID that is going to belong to
                      the transaction object.
  Post-Condition:
      The customer id is set for the object.
  ----------------------------------------------------------------------------*/
  void Transaction::setCustomerID(int customerID)
  {
      this->customerID = customerID;
  }

  /*-------------------------------getCustomerID-------------------------------
  getCustomerID:
      This is a basic getter that return the id of the customer for the
      transaction object.
  ----------------------------------------------------------------------------*/
  int Transaction::getCustomerID()const
  {
      return this->customerID;
  }

  /*------------------------------setTransactionType---------------------------
  setTransactionType:
      A Basic setter that sets the transaction type according to the parameter.
  Pre-Condition:
      char type - Represents the type of transaction that we want for the object.
  Post Condition:
      The transaction type is set to the parameter.
  ----------------------------------------------------------------------------*/
  void Transaction::setTransactionType(char type)
  {
      this->transactionType = type;
  }

  /*-------------------------------getTransactionType--------------------------
  getTransactionType:
      A basic getter that returns the transaction type of the transaction.
  ----------------------------------------------------------------------------*/
  char Transaction::getTransactionType()const
  {
      return this->transactionType;
  }

  /*--------------------------------setMovie-----------------------------------
  setMovie:
      A basic setter that will hold the movie that is desired to keep in
      the transaction.
  Pre-Condition:
      Movie *movie - Represents the movie object that we want to hold so we
                     can retrieve details from the movie
  Post Conditions:
      The private movie variable is set to the movie passed in.
  ----------------------------------------------------------------------------*/
  void Transaction::setMovie(Movie *movie)
  {
      this->movie = movie;
  }

  /*---------------------------------getMovie----------------------------------
  getMovie:
      A basic getter that returns the movie that is in the transaction.
  ----------------------------------------------------------------------------*/
  Movie* Transaction::getMovie()const
  {
      return this->movie;
  }

  /*---------------------------------doTrans-----------------------------------
   doTrans:
      This method increases the stock of the movie in the transaction.
      NOTE: This method is unimplemented because it is just a template for
            the subclasses.
  ----------------------------------------------------------------------------*/
  void Transaction::doTrans(){}

  /*---------------------------------display-----------------------------------
   display:
      Method that displays the borrowed movie and the details that come with it.
      NOTE: This method is unimplemented because it is just a template for
            the subclasses.
  ----------------------------------------------------------------------------*/
  void Transaction::display()const{}
