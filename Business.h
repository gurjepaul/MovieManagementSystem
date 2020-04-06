/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Business
Description:
    The Business class is meant to represent a Dvd store that contains an
    inventory of movies, and also a list of customers. This store is meant
    to provide basic functionality such as letting customers borrow, and
    return movies. As well as show the history of a customer and show the
    current inventory in the store.
------------------------------------------------------------------------------*/

#ifndef Business_h
#define Business_h

#include <string>
#include <iostream>
#include <fstream>
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
#include "HashTable.h"
#include "Customer.h"
#include "Transaction.h"
#include "Return.h"
#include "Borrow.h"
#include "Inventory.h"

using namespace std;

class Business
{
public:
    Business(string const &movieFile);
    ~Business();
    
    void buildCustomers(string const &customerData);
    void executeCommands(string const &commandData);

private:
    
    HashTable customers;
    Inventory movies;
    
};
#endif /* Business_h */
