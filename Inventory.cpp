/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
 
Due Date: March 14, 2020
Class Inventory
Description:
 
    The Inventory class is representative of an Inventory that contains movies
    and orders them in terms of what type of movie they are. The inventory class
    is also able to provide whether or not a certain movie is in the inventory,
    as well as show the current list of movies in the store.
 ------------------------------------------------------------------------------*/

#include <stdio.h>
#include "Inventory.h"

// ------------------------------------Constructor--------------------------------------------
Inventory::Inventory(){}

// -------------------------------------Destructor--------------------------------------------
Inventory::~Inventory()
{
    DeleteMovies();
}

// -----------------------------------buildInventory------------------------------------------
// Description
// buildInventory: builds the movie inventory using information from a file passed into the
// method
// preconditions: There must be a file to read from, containers to hold each movie
// postconditions: Vectors that hold movie objects
// -------------------------------------------------------------------------------------------
void Inventory::buildInventory(string const &movieFile)
{
    //Create a new file reader
    ifstream movies(movieFile);
    if(!movies)
    {
        cerr << "ERROR: Invalid input file" << endl;
        return;
    }
    //While the file still has lines
    while(!movies.eof())
    {
            
        char type;
        //Retrieve what type of movie we want to create
        movies >> type;
        
        switch(type)
        {
            //If the letter is C
            case 'C':
            {
                //Create a new Classic movie object
                Classic *c = new Classic();
                c->setData(movies);
                //And place in the vector of Classic movies
                classics.push_back(*c);
                break;
            }
            //If the letter is F
            case 'F':
            {
                //Create a new Comedy movie object
                Comedy *f = new Comedy();
                f->setData(movies);
                //And place in the vector of Comedy movies
                comedies.push_back(*f);
                break;
            }
            //If the letter is D
            case 'D':
            {
                //Create a new Drama movie object
                Drama *d = new Drama();
                d->setData(movies);
                //And place in the vector of Drama movies
                dramas.push_back(*d);
                break;
            }
            //If the letter is something else
            default:{
                //Alert the business of an invalid movie
                cerr << "ERROR: Invalid movie type " << type << endl;
                movies.ignore(1000000, '\n');
                break;
            }
        }
        
    }
    movies.close();
}

// ------------------------------------viewClassics-------------------------------------------
// Description
// viewClassics: Outputs all the Classic movie objects of the movie store
// preconditions: Vector of Classic movie objects
// postconditions: Console output of the classic movies in the system
// -------------------------------------------------------------------------------------------
void Inventory::viewClassics()
{
    //Loop that goes through the Classics vector and displays the movies
    for(int i = 0;i < classics.size(); i++)
    {
        classics[i].display();
    }
    
    cout << endl;
}

// ------------------------------------viewComedies-------------------------------------------
// Description
// viewComedies: Outputs all the Comedy movie objects of the movie store
// preconditions: Vector of Comedy movie objects
// postconditions: Console output of the comedy movies in the system
// -------------------------------------------------------------------------------------------
void Inventory::viewComedies()
{
    //Loop that goes through the Comedies vector and displays the movies
    for(int i = 0;i < comedies.size(); i++)
    {
        comedies[i].display();
    }
    
    cout << endl;
}

// ------------------------------------viewDramas---------------------------------------------
// Description
// viewDramas: Outputs all the Dramas movie objects of the movie store
// preconditions: Vector of Dramas movie objects
// postconditions: Console output of the drama movies in the system
// -------------------------------------------------------------------------------------------
void Inventory::viewDramas()
{
    //Loop that goes through the Dramas vector and displays the movies
    for(int i = 0;i < dramas.size(); i++)
    {
        dramas[i].display();
    }
    
    cout << endl;
}

// -----------------------------------viewInventory-------------------------------------------
// Description
// viewInventory: Outputs all the movie objects of the movie store
// preconditions: Vectors of all the movie objects
// postconditions: Console output of all the movies in the system
// -------------------------------------------------------------------------------------------
void Inventory::viewInventory()
{
    cout << "Movie Store Inventory" << endl;
    cout << " Comedies:" << endl;
    viewComedies();
    
    cout << " Dramas:" << endl;
    viewDramas();
    
    cout << " Classics:" << endl;
    viewClassics();
}

// -----------------------------------findClassicMovie---------------------------------------------------
// Description
// findClassicMovie: finds and returns true if a desired movie selection is in the movie store and if
// a customer is able to borrow/return it
// preconditions: Vectors of the Classic movie objects, generic classic movie information
// postconditions: Returns true if the movie can be used in a transaction, false if not
// ------------------------------------------------------------------------------------------------------
bool Inventory::findClassicMovie(int releaseMonth, int releaseYear, string majorActor, Movie *&selection)
{
    // Searching through the classic movie vector to find the desired movie
    for (int i = 0; i < classics.size(); i++)
    {
            // If we locate the desired movie
            if (releaseMonth == classics[i].getReleaseMonth() && releaseYear == classics[i].getReleaseYear()
                && majorActor == classics[i].getMajorActor())
            {
                // Return false if it is out of stock
                if (classics[i].getStock() == 0)
                {
                    cerr << "ERROR: Desired movie out of stock" << endl;
                    findClassicDuplicate(classics[i].getTitle(), classics[i].getMajorActor());
                    // FIND OUT IF THERE IS ANOTHER ONE
                    return false;
                }
                // In stock so we send the desired movie over and return true
                selection = &classics[i];
                return true;
            }
        }
    // No such movie in the database
    cerr << "ERROR: Movie not found in database" << endl;
    return false;
}

// -----------------------------------findClassicDuplicate---------------------------------
// Description
// findClassicDuplicate: finds an alternative classic movie with a different major actor
// if the one the customer wants to select is out of stock
// preconditions: Vectors of the Classic movie objects, generic classic movie information
// postconditions: Outputs the alternative movie info to the console
// ----------------------------------------------------------------------------------------
void Inventory::findClassicDuplicate(string title, string majorActor)
{
    // Searching through the classic movie vector to find an alternative movie
    for (int i = 0; i < classics.size(); i++)
    {
        // If there is the same movie with a different major actor in stock display a message
        if (title == classics[i].getTitle() && majorActor != classics[i].getMajorActor() && classics[i].getStock() > 0)
        {
            cout << "Alternative: ";
            classics[i].display();
            cout << endl;
            return;
        }
    }
}

// -----------------------------------findComedyMovie---------------------------------------------------
// Description
// findComedyMovie: finds and returns true if a desired movie selection is in the movie store and if
// a customer is able to borrow/return it
// preconditions: Vectors of the Comedy movie objects, generic Comedy movie information
// postconditions: Returns true if the movie can be used in a transaction, false if not
// -----------------------------------------------------------------------------------------------------
bool Inventory::findComedyMovie(string title, int releaseYear, Movie *&selection)
{
    // Searching through the comedy movie vector to find the desired movie
    for (int i = 0; i < comedies.size(); i++)
    {
        // If we locate the desired movie
        if (title == comedies[i].getTitle() && releaseYear == comedies[i].getReleaseYear())
        {
            // Return false if it is out of stock
            if (comedies[i].getStock() == 0)
            {
                cerr << "ERROR: Movie out of stock" << endl;
                return false;
            }
            // In stock so we send the desired movie over and return true
            selection = &comedies[i];
            return true;
        }
    }
    // No such movie in the database
    cerr << "ERROR: Movie not found in database" << endl;
    return false;
}

// -----------------------------------findDramaMovie---------------------------------------------------
// Description
// findDramaMovie: finds and returns true if a desired movie selection is in the movie store and if
// a customer is able to borrow/return it
// preconditions: Vectors of the Drama movie objects, generic Drama movie information
// postconditions: Returns true if the movie can be used in a transaction, false if not
// ----------------------------------------------------------------------------------------------------
bool Inventory::findDramaMovie(string director, string title, Movie *&selection)
{
    // Searching through the drama movie vector to find the desired movie
    for (int i = 0; i < dramas.size(); i++)
    {
        // If we locate the desired movie
        if (director == dramas[i].getDirector() && title == dramas[i].getTitle())
        {
            // Return false if it is out of stock
            if (dramas[i].getStock() == 0)
            {
                cerr << "ERROR: Movie out of stock" << endl;
                return false;
            }
            // In stock so we send the desired movie over and return true
            selection = &dramas[i];
            return true;
        }
    }
    // No such movie in the database
    cerr << "ERROR: Movie not found in database" << endl;
    return false;
}

// -------------------------------------DeleteMovies---------------------------------------------------
// Description
// DeleteMovies: Deallocated all the movie objects in the vectors that store movie information
// preconditions: Vectors of the movie objects
// postconditions: Empty vectors
// ----------------------------------------------------------------------------------------------------
void Inventory::DeleteMovies()
{
//    for (int i = 0; i < classics.size(); i++)
//    {
//    }
//
//    for (int j = 0; j < comedies.size(); j++)
//    {
//    }
//
//    for (int k = 0; k < dramas.size(); k++)
//    {
//    }
}
