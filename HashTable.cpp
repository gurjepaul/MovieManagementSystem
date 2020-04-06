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

#include <stdio.h>
#include "HashTable.h"

/*-----------------------------------HashTable---------------------------------
HashTable:
   This is a basic constructor that initializes every head in every index of
   the array.

   Post Conditions:
   Every head in the hashtable is set to null.
----------------------------------------------------------------------------*/
HashTable::HashTable()
{

    //For loop establishes the array by making every head null
    for(int i = 0; i < sizeOfTable; i++)
    {
        table[i].head = nullptr;
    }

}

/*------------------------------~HashTable-----------------------------------
~HashTable:
    This is a basic destructor that empties/deallocates memory used for the
    hash table. The method calls the helper method emptyTable to free
    the memory.
    Post Condition:
    Every node and item in the hash table is deleted.
----------------------------------------------------------------------------*/
HashTable::~HashTable()
{
    this->emptyTable();
}

/*-------------------------------addCustomer---------------------------------
addCustomer:
    This method inserts a new Customer to the hash table by creating a hash
    key and inserting the customer in the specific index.
    
    Pre-Conditions:
    Customer *cust - A customer object has been created and is wanting to be
        inserted into the hash table.
 
    Post Conditions:
    A Customer object has been inserted into the hash table.
----------------------------------------------------------------------------*/
bool HashTable::addCustomer(Customer *cust)
{
    //Retrieves the hash number to see where the customer will be placed
    //The hash number is also known as the index. Which can represent
    //the index the Customer will stay in the array
    int index = cust->getId() % hashTable;
    
    //Create a new item with the Customer
    item *temp = new item;
    temp->c = cust;
    temp->next = nullptr;
    
    //If the index in the array is null, then place the item in this spot
    if(table[index].head == nullptr)
    {
        table[index].head = temp;
    }
    //If the index is full, then complete the next steps
    else
    {
        //Create a temp pointer for the current index
        item *ptr = table[index].head;
        
        //While the next item in the index isn't null
        while(ptr->next != nullptr)
        {
            //Check to see if the customer already exists in the hash table
            if(cust->getId() == ptr->c->getId())
            {
                //Alert the business of a duplicate and delete the temp pointer
                cerr << "ERORR: Customer " << cust->getId() << " already in system" << endl;
                temp->c = nullptr;
                delete temp;
                temp = nullptr;
                return false;
            }
            //If the current customer isn't a duplicate, we keep going in the
            //list for the current index
            ptr = ptr->next;
        }
        //Once we've reached the end of the list for the current index
        //We assign the new customer to this spot in the index
        ptr->next = temp;
        
    }
    
    return true;
}

/*-----------------------------------getCustomer-----------------------------
getCustomer:
    This method allows for the hash table to retrieve a customer object
    by creating a hash key and then directly accessing the Customer in the
    table by using this hash key.
 
    Pre-Conditions:
    int custId - Represents the customer id that comes from the customer
        that we want to retrieve.
 
    Post Conditions:
    A customer object is returned to be changed if desired from the business.
----------------------------------------------------------------------------*/
Customer* HashTable::getCustomer(int custId)
{
    //Create the hash value for the customer we want
    int index = custId % hashTable;
    
    //Check the spot in the hashtable and see if it is empty
    if(table[index].head == nullptr)
    {
        //If it is empty, we return null
        return nullptr;
    }
    //Else, this means that the customer might be in the hash table
    else{
        //Create a temp pointer to start the list for the index
        item *cur = table[index].head;
        //While the next customer in the list is not null, then we go into the loop
        while(cur != nullptr)
        {
            //Check to see if the customer IDs match with each other
           if(cur->c->getId() == custId)
           {
               //If the customer exist, we return a pointer for the customer
               return cur->c;
           }
            //If the customer doesn't exist at the current spot in the list
            //We go to the next item
            cur = cur->next;
        }
    }
    //Return null if we did not find the customer in the hash table
    return nullptr;
}

/*------------------------------------emptyTable------------------------------
emptyTable:
    This method acts as a helper method that frees memory in the hashtable
    by deleting every node and item in the hash table.
 
    Post Condition:
    Every node and item in the hash table is deleted.
----------------------------------------------------------------------------*/
void HashTable::emptyTable()
{
    //Loop through the hashtable
    for(int i = 0; i < sizeOfTable; i++)
    {
        //Go through the list in the index and delete data and the node
        if(table[i].head != nullptr)
        {
            item* cur = table[i].head;
            while(table[i].head != nullptr)
            {
                table[i].head = table[i].head->next;
                //Check to see if the Customer is null
                if(cur->c != nullptr)
                {
                    //If so, delete the customer in the index
                    delete cur->c;
                    cur->c = nullptr;
                }
                //Then delete the temporary node
                delete cur;
                cur = nullptr;
                cur = table[i].head;
            }
        }
    }
}
