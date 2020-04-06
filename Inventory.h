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

#ifndef Inventory_h
#define Inventory_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Inventory
{
private:
    vector<Classic> classics;
    vector<Comedy> comedies;
    vector<Drama> dramas;
    
    void findClassicDuplicate(string title, string majorActor);
    void DeleteMovies();
    
public:
    //Constuctors
    Inventory();
    ~Inventory();
    
    //Builds an inventory
    void buildInventory(string const &movieFile);
    
    //Methods that help display the movies in the inventory
    void viewClassics();
    void viewComedies();
    void viewDramas();
    void viewInventory();
    
    //Methods that retrieve movies from the inventory
    bool findClassicMovie(int month, int year, string title, Movie *&selection);
    bool findComedyMovie(string title, int releaseYear, Movie *&selection);
    bool findDramaMovie(string director, string title, Movie *&selection);        
};
#endif /* Inventory_h */
