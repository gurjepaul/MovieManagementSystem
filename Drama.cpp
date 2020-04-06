/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Drama
Description:
    The Drama class is made to represent a Drama movie containing most of the
    major details that are derived from the parent class Movie. Details include
    a title, a director and a release date. When a customer wants to borrow a
    Drama movie from the business, this object is called.
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "Drama.h"

/*---------------------------------Drama------------------------------------
 Drama:
 
    This is a basic constructor that sets the movie type to D and creates a
    new Drama object
----------------------------------------------------------------------------*/
Drama::Drama()
{
    setMovieType('D');
}
/*---------------------------------Drama------------------------------------
 Drama:
 
    This is a basic constructor that sets the variables from the parameters
    given to the method.
    Pre-Condition:
    int stock - Represents the amount of movies the object has
    string director - Represents the directors name
    string title - Represents the title of the movie
    int releaseYear - Represents the release year of the movie
 
    Post Condition:
    Sets the variables to the values of the parameters
----------------------------------------------------------------------------*/
Drama::Drama(int stock, string director, string title, int releaseYear)
{
    setMovieType('D');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}
/*---------------------------------~Drama------------------------------------
 ~Drama:
 
    This is a basic destructor for the Drama object
----------------------------------------------------------------------------*/
Drama::~Drama(){}
/*---------------------------------setData-----------------------------------
 setData:
    This method is a setter method that takes in the file that contains
    the information for Drama object and it sets the variables for the object
 
    Pre-Condition:
    ifstream &file - Represents the file that we are wanting to read from
 
    Post Condition:
    Sets the data from the file to the Drama object
----------------------------------------------------------------------------*/
void Drama::setData(ifstream &file)
{
    int stock, releaseYear;
    string director, title;
    
    file.ignore(1);
    file >> stock;
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}
/*-------------------------------operator==-----------------------------------
 operator==:
 
    This is an == operator overload that compares the current Drama movie
    to another drama movie.
    Pre-Condition:
    Movie &dram - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Drama movies are equal or not
----------------------------------------------------------------------------*/
bool Drama::operator==(const Movie& dram)const
{
    //If both stocks are the same
    if(getStock() == dram.getStock())
    {
         //If both directors are the same
        if(getDirector().compare(dram.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(dram.getTitle()) == 0)
            {
                //If both release years are the same
                if(getReleaseYear() == dram.getReleaseYear())
                {
                     //Return true if all the variables are equal
                    return true;
                }
            }
        }
    }
    //Return false if one of the variables are different
    return false;
}
/*------------------------------operator!=-----------------------------------
 operator!=:
 
    This is an != operator overload that compares the current Drama movie
    to another drama movie.
    Pre-Condition:
    Movie &dram - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Drama movies are not equal.
----------------------------------------------------------------------------*/
bool Drama::operator!=(const Movie& dram)const
{
     return !(*this == dram);
}
/*-------------------------------operator>-----------------------------------
 operator>:
 
    This is a > operator overload that checks to see if the current Drama
    movie is greater than the other Drama
    Pre-Condition:
    Movie &dram - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Drama movies is greater than the other
    Drama object.
----------------------------------------------------------------------------*/
bool Drama::operator>(const Movie& dram) const
{
    //If the current director is greater than the other movie
    if(getDirector().compare(dram.getDirector()) > 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current director is equal to the other movie
    else if(getDirector().compare(dram.getDirector()) == 0)
    {
        //If so, check to see if the current title is greater than the other movie
        if(getTitle().compare(dram.getTitle()) > 0)
        {
            //If so, return true;
            return true;
        }
        //If the the current title equals the other title
        else if(getTitle().compare(dram.getTitle()) == 0)
        {
            //Return false
            return false;
        }
        else
        {
            //Return false if the current title is less than the other one
            return false;
        }
    }
    else
    {
        //Return false if the current director is less than the other one
        return false;
    }
}
/*-------------------------------operator<-----------------------------------
 operator<:
 
    This is a < operator overload that checks to see if the current Drama
    movie is less than the other Drama
    Pre-Condition:
    Movie &dram - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Drama movies is less than the other
    Drama object.
----------------------------------------------------------------------------*/
bool Drama::operator<(const Movie& dram) const
{
    //If the current director is less than the other movie
     if(getDirector().compare(dram.getDirector()) < 0)
     {
         //Return true
         return true;
     }
    //Otherwise, check to see if the current director is equal to the other movie
     else if(getDirector().compare(dram.getDirector()) == 0)
     {
         //If so, check to see if the current title is less than the other movie
         if(getTitle().compare(dram.getTitle()) < 0)
         {
             //If so, return true;
             return true;
         }
         //If the the current title equals the other title
         else if(getTitle().compare(dram.getTitle()) == 0)
         {
             //Return false
             return false;
         }
         else
         {
             //Return false if the current title is greater than the other one
             return false;
         }
     }
     else
     {
         //Return false if the current director is greater than the other one
         return false;
     }
}
/*---------------------------------operator=---------------------------------
 operator=:
 
    This is an = operator overload that creates a copy of another Drama object
    and establishes the information to the current Drama object.
    Pre-Condition:
    Movie &d - Represents the movie that we want to copy information from
 
    Post Condition:
    Returns a copy of the movie that was passed in and assigns it to the
    current Drama object
----------------------------------------------------------------------------*/
Movie* Drama::operator=(const Movie &d)
{
    setStock(d.getStock());
    setDirector(d.getDirector());
    setTitle(d.getTitle());
    setReleaseYear(d.getReleaseYear());
    
    return this;
}
/*-------------------------------display------------------------------------
 display:
 
    This method displays the contents of the Drama object.
----------------------------------------------------------------------------*/
void Drama::display()
{
    //Displays the credentials of a Drama movie
    cout << getMovieType() << ", " << getStock() << ", "
    << getDirector() << ", " << getTitle() << ", " << getReleaseYear() << endl;
}
