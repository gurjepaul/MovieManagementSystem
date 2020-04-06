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

#include <stdio.h>
#include "Business.h"

// ------------------------------------Constructor--------------------------------------------
Business::Business(string const &movieData)
{
    // building the movie store inventory
    movies.buildInventory(movieData);
}

// ------------------------------------Destructor---------------------------------------------
Business::~Business(){}

// -----------------------------------buildCustomers------------------------------------------
// Description
// buildCustomers: builds the movie start hashtable of customers using data from a file
// containing information of potential customers
// preconditions: There must be a file to read from, hashtable object
// postconditions: Hashtable filled with valid customer objects
// -------------------------------------------------------------------------------------------
void Business::buildCustomers(string const &customerData)
{
    // Creating file and checking its validity
    ifstream customersFile(customerData);
    if (!customersFile)
    {
        cerr << "ERROR: Invalid customer input file" << endl;
        return;
    }
    
    Customer *theCustomer = NULL;
    
    // Looping through the customer data file
    while (!customersFile.eof())
    {
        theCustomer = new Customer();
        
        // Attempting to create and add customer to the database
        if (theCustomer->setData(customersFile))
        {
            // If customer can't be added, deallocate the data accordingly
            if (!customers.addCustomer(theCustomer))
            {
                delete theCustomer;
                theCustomer = NULL;
            }
            theCustomer = NULL;
        }
        // Deallocating the data accordingly
        else
        {
            delete theCustomer;
            theCustomer = NULL;
        }
    }
    customersFile.close();
}

// ----------------------------------executeCommands------------------------------------------
// Description
// executeCommands: completes a sequence of arbitrary commands from a text file passed in
// preconditions: There must be a file to read from
// postconditions: Movie stocks need to be updated, Customers histories will be updated
// -------------------------------------------------------------------------------------------
void Business::executeCommands(string const &commandData)
{
    // Creating file and checking its validity
    ifstream commandsFile(commandData);
    if (!commandsFile)
    {
        cerr << "ERROR: Invalid command input file" << endl;
        return;
    }
    
    string currentLine;

    // Looping throught each line in the commands data file
    while(!commandsFile.eof())                       
    {
        // store in information of the first char
        char commandType, movieType;
        commandsFile >> commandType;

        // Switch statement for which command is attempted
        switch(commandType)
        {
            // If the transaction is a borrow
            case 'B':
            {
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // continue to next iteration of loop if customer isn't in database
                if (customer == NULL)
                {
                    continue;
                }
                
                // reading in the char for DVD which we can ignored
                char format;
                commandsFile >> format;
                
                // store category type
                commandsFile >> movieType;
                
                // Switch statement for which category the movie belongs to
                switch(movieType)
                {
                    // Classic movie
                    case 'C':
                    {
                        int releaseMonth, releaseYear;
                        commandsFile >> releaseMonth >> releaseYear;
                        
                        string firstName, lastName;
                        commandsFile >> firstName >> lastName;
                        
                        string majorActor = firstName + " " + lastName;
                        
                        // Checking if their movie choice is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, selection);
                        
                        // If the movie is in the database
                        if (validMovie)
                        {
                            // Creating a transaction object
                            Transaction *t = new Borrow('B', selection);
                            
                            // Completing the transaction and adding to the customers history for a valid transaction
                            if (customer->borrowIsValid('C', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            // Dellocating data for an invalid return
                            else
                            {
                                delete t;
                                t = NULL;
                            }
                        }
                        break;
                    }
                    // Drama movie
                    case 'D':
                    {
                        string director, title;
                        
                        commandsFile.ignore(1);
                        getline(commandsFile, director, ',');
                        
                        commandsFile.ignore(1);
                        
                        getline(commandsFile, title, ',');
                        
                        // Checking if their movie choice is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findDramaMovie(director, title, selection);
                        
                         // If the movie is in the database
                        if(validMovie)
                        {
                            // Creating a transaction object
                            Transaction *t = new Borrow('B', selection);
                            
                            // Completing the transaction and adding to the customers history for a valid transaction
                            if(customer->borrowIsValid('D', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            // Dellocating data for an invalid return
                            else
                            {
                                delete t;
                                t = nullptr;
                            }
                        }
                         
                        break;
                    }
                    // Comedy movie
                    case 'F':
                    {
                        string title;
                        
                        commandsFile.ignore(1);
                        getline(commandsFile, title, ',');
                        
                        commandsFile.ignore(1);
                        
                        int releaseYear;
                        commandsFile >> releaseYear;
                        
                        // Checking if their movie choice is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findComedyMovie(title, releaseYear, selection);
                        
                         // If the movie is in the database
                        if(validMovie)
                        {
                            // Creating a transaction object
                            Transaction *t = new Borrow('B', selection);
                            
                             // Completing the transaction and adding to the customers history for a valid transaction
                            if(customer->borrowIsValid('F', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            // Dellocating data for an invalid return
                            else
                            {
                                delete t;
                                t = nullptr;
                            }
                        }
                         
                        break;
                    }
                    //Default
                    default:
                    {
                        cerr << "ERROR: Invalid movie type" << endl;
                    }
                }
                break;
            }
            // If the transaction is a return
            case 'R':
            {
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // continue to next iteration of loop if customer isn't in database
                if (customer == NULL)
                {
                    continue;
                }
                
                // reading in the char for DVD which we can ignored
                char format;
                commandsFile >> format;
                
                // store category type
                commandsFile >> movieType;
                
                // Switch statement for which category the movie belongs to
                switch(movieType)
                {
                    // Classic movie
                    case 'C':
                    {
                        int releaseMonth, releaseYear;
                        commandsFile >> releaseMonth >> releaseYear;
                    
                        string firstName, lastName;
                        commandsFile >> firstName >> lastName;
                    
                        string majorActor = firstName + " " + lastName;
                    
                        // Checking if their movie choice is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findClassicMovie(releaseMonth, releaseYear, majorActor, selection);
                    
                        // If the movie is in the database
                        if (validMovie)
                        {
                            // Creating a transaction object
                            Transaction *t = new Return('R', selection);
                        
                            // Completing the transaction and adding to the customers history for a valid transaction
                            if (customer->returnIsValid('C', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            // Dellocating data for an invalid return
                            else
                            {
                                delete t;
                                t = NULL;
                            }
                        }
                        break;
                    }
                    // Drama movie
                    case 'D':
                    {
                        string title, director;
                        
                        commandsFile.ignore(1);
                        getline(commandsFile, director, ',');
                        
                        commandsFile.ignore(1);
                        
                        getline(commandsFile, title, ',');
                        
                        //Checking if their movie choise is valid and getting it if it is true
                        Movie *selection;
                        bool validMovie = movies.findDramaMovie(director, title, selection);
                        
                        //If the movie is in the database
                        if(validMovie)
                        {
                            //Creating a transaction object
                            Transaction *t = new Return('R', selection);
                            
                            //Completing the transaction and adding to the customer's history for a valid transaction
                            if(customer->returnIsValid('D', t))
                            {
                                t->doTrans();
                                customer->addTransaction(t);
                            }
                            //Deallocating data for an invalid return
                            else
                            {
                                delete t;
                                t = nullptr;
                            }
                        }
                        break;
                    }
                    // Comedy movie
                    case 'F':
                    {
                        string title;
                        
                        commandsFile.ignore(1);
                        getline(commandsFile, title, ',');
                        
                        commandsFile.ignore(1);
                        
                        int releaseYear;
                       commandsFile >> releaseYear;
                       
                        //Checking if their movie choise is valid and getting it if it is true
                       Movie *selection;
                       bool validMovie = movies.findComedyMovie(title, releaseYear, selection);
                       
                         //If the movie is in the database
                       if(validMovie)
                       {
                           //Creating a transaction object
                           Transaction *t = new Return('R', selection);
                           
                           //Completing the transaction and adding to the customer's history for a valid transaction
                           if(customer->returnIsValid('F', t))
                           {
                               t->doTrans();
                               customer->addTransaction(t);
                           }
                           //Deallocating data for an invalid return
                           else
                           {
                               delete t;
                               t = nullptr;
                           }
                       }
                        break;
                    }
                    //Default
                    default:
                    {
                        cerr << "ERROR: Invalid movie type " << movieType << endl;
                    }
                }
                break;
            }
            // If the command is to show the inventory of the store
            case 'I':
            {
                movies.viewInventory();
                break;
            }
            // If the command is to show the history of the customer
            case 'H':
            {
                // store id of the customer
                int customerID;
                commandsFile >> customerID;
                
                // attempting to get the desired Customer object for the transaction
                Customer *customer = NULL;
                customer = customers.getCustomer(customerID);
                
                // output history for customer if the the customer is in the system
                if (customer != NULL)
                {
                    customer->viewHistory();
                }
                break;
            }
            default:
            {
                cerr << "ERROR: Invalid command type " << commandType << endl;
            }
        }
        getline(commandsFile, currentLine);
    }
    commandsFile.close();
}
