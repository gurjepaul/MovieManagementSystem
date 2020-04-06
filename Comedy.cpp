/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Comedy
Description:
    The Comedy class is made to represent a Comedy movie containing most of the
    major details that are derived from the parent class Movie. Details include
    a title, a director and a release date. When a customer wants to borrow a
    Comedy movie from the business, this object is called.
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "Comedy.h"

/*----------------------------------Comedy-----------------------------------
 Comedy:
 
    This is a basic constructor that sets the movie type to F and creates a
    new Comedy object
----------------------------------------------------------------------------*/
Comedy::Comedy()
{
    setMovieType('F');
}
/*---------------------------------Comedy------------------------------------
 Comedy:
 
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
Comedy::Comedy(int stock, string director, string title, int releaseYear)
{
    setMovieType('F');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}
/*---------------------------------~Comedy------------------------------------
 ~Comedy:
 
    This is a basic destructor for the Comedy object
----------------------------------------------------------------------------*/
Comedy::~Comedy()
{
    
}
/*---------------------------------setData-----------------------------------
 setData:
    This method is a setter method that takes in the file that contains
    the information for Comedy object and it sets the variables for the object
 
    Pre-Condition:
    ifstream &file - Represents the file that we are wanting to read from
 
    Post Condition:
    Sets the data from the file to the Comedy object
----------------------------------------------------------------------------*/
void Comedy::setData(ifstream &file)
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
 
    This is an == operator overload that compares the current Comedy movie
    to another Comedy movie.
    Pre-Condition:
    Movie &fun - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Comedy movies are equal or not
----------------------------------------------------------------------------*/
bool Comedy::operator==(const Movie& fun)const
{
    //If both stocks are the same
    if(getStock() == fun.getStock())
    {
        //If both directors are the same
        if(getDirector().compare(fun.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(fun.getTitle()) == 0)
            {
                //If both release years are the same
                if(getReleaseYear() == fun.getReleaseYear())
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
 
    This is an != operator overload that compares the current Comedy movie
    to another Comedy movie.
    Pre-Condition:
    Movie &fun - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Comedy movies are not equal.
----------------------------------------------------------------------------*/
bool Comedy::operator!=(const Movie& fun)const
{
     return !(*this == fun);
}
/*-------------------------------operator>-----------------------------------
 operator>:
 
    This is a > operator overload that checks to see if the current Comedy
    movie is greater than the other Comedy
    Pre-Condition:
    Movie &fun - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Comedy movies is greater than the other
    Comedy object.
----------------------------------------------------------------------------*/
bool Comedy::operator>(const Movie& fun) const
{
    //If the current title is greater than the other movie
    if(getTitle().compare(fun.getTitle()) > 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current title is equal to the other movie
    else if(getTitle().compare(fun.getTitle()) == 0)
    {
        //If so, check to see if the current release year is greater than the other movie
        if(getReleaseYear() > fun.getReleaseYear())
        {
            //If so, return true;
            return true;
        }
        else
        {
            //Return false if the current release year is not greater
            return false;
        }
    }
    else
    {
        //Return false if the current title is less than the other movie
        return false;
    }
}
/*-------------------------------operator<-----------------------------------
 operator<:
 
    This is a < operator overload that checks to see if the current Comedy
    movie is less than the other Comedy
    Pre-Condition:
    Movie &fun - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Comedy movies is less than the other
    Comedy object.
----------------------------------------------------------------------------*/
bool Comedy::operator<(const Movie& fun) const
{
    //If the current title is less than the other movie
    if(getTitle().compare(fun.getTitle()) < 0)
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current title is equal to the other movie
    else if(getTitle().compare(fun.getTitle()) == 0)
    {
        //If so, check to see if the current release year is less than the other movie
        if(getReleaseYear() < fun.getReleaseYear())
        {
            //If so, return true;
            return true;
        }
        else
        {
            //Return false if the current release year is not less
            return false;
        }
    }
    else
    {
        //Return false if the current title is greater than the other movie
        return false;
    }
}
/*---------------------------------operator=---------------------------------
 operator=:
 
    This is an = operator overload that creates a copy of another Comedy object
    and establishes the information to the current Comedy object.
    Pre-Condition:
    Movie &f - Represents the movie that we want to copy information from
 
    Post Condition:
    Returns a copy of the movie that was passed in and assigns it to the
    current Comedy object
----------------------------------------------------------------------------*/
Movie* Comedy::operator=(const Movie &f)
{
    setStock(f.getStock());
    setDirector(f.getDirector());
    setTitle(f.getTitle());
    setReleaseYear(f.getReleaseYear());
    
    return this;
}
/*-------------------------------display------------------------------------
 display:
 
    This method displays the contents of the Comedy object.
----------------------------------------------------------------------------*/
void Comedy::display()
{
    //Displays the credentials of a Comedy movie
    cout << getMovieType() << ", " << getStock() << ", "
    << getDirector() << ", " << getTitle() << ", " << getReleaseYear() << endl;
}
