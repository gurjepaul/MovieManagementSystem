/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class HashTable
Description:
 
 This class represents a hash table that has basic functionalities like
 inserting and retrieving from the table. Specifically this table will be able
 to store Customer objects and their data.
 
 NOTE: This hash table deals with collisions be using an open hashing method
       which will create inner linked lists in the case of collisions.
------------------------------------------------------------------------------*/

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include "Customer.h"
using namespace std;

class HashTable
{
    
    static const int sizeOfTable = 100; //Establishes the size of the table
    static const int hashTable = 101;
    
private:
    
    //Struct created to hold the Customer object
    struct item
    {
        Customer *c;
        item *next;
    };
    
    //Struct that holds the head item for the linked list in every element of the hash table
    struct hashStore
    {
        item *head;
    };
    
    hashStore table[sizeOfTable];   //Array that holds the hashStore objects which contains the items
    
    void emptyTable(); //Method that clears the table
    
public:
    //Constructors
    HashTable();
    ~HashTable();
    
    bool addCustomer(Customer *c);  //Method that adds a customer to the table
    Customer* getCustomer(int custId);  //Method that retrieves a customer from the table
    
};
#endif /* HashTable_h */
