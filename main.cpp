/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class main
Description:
    Driver for program 4
------------------------------------------------------------------------------*/

#include <iostream>
#include "Inventory.h"
#include "Business.h"
#include "Movie.h"

int main(int argc, const char * argv[])
{
    // Creating the business which creates the inventory
    Business a("data4movies.txt");
    
    // Calling a method that take in and build all the customers
    a.buildCustomers("data4customers.txt");
    
    // Calling a method that take in and execute all the commands
    a.executeCommands("data4commands.txt");
}
