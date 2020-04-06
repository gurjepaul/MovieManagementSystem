/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Classic
Description:
    The Classic class is made to represent a Classic movie containing most of the
    major details that are derived from the parent class Movie. Details include
    a title, a director and a release date. When a customer wants to borrow a
    Classic movie from the business, this object is called.
 
    NOTE: The Classic class contains two more variables than the other
          subclasses (Major Actor, and Release Month).
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "Classic.h"

/*-------------------------------Classic-------------------------------------
 Drama:
    This is a basic constructor that sets the movie type to C and creates a
    new Classic object
----------------------------------------------------------------------------*/
Classic::Classic()
{
    setMovieType('C');
}
/*-------------------------------Classic--------------------------------------
 Classic:
    This is a basic constructor that sets the variables from the parameters
    given to the method.
    Pre-Condition:
    int stock - Represents the amount of movies the object has
    string director - Represents the directors name
    string title - Represents the title of the movie
    string majorActor - Represents the major actor for the movie
    int releaseMonth - Represents the release month for the movie
    int releaseYear - Represents the release year of the movie
 
    Post Condition:
    Sets the variables to the values of the parameters
----------------------------------------------------------------------------*/
Classic::Classic(int stock, string director, string title, string majorActor, int releaseMonth,  int releaseYear)
{
    setMovieType('C');
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
}
/*--------------------------------~Classic-----------------------------------
 ~Drama:
    This is a basic destructor for the Classic object
----------------------------------------------------------------------------*/
Classic::~Classic()
{
    
}
/*--------------------------------setData------------------------------------
 setData:
    This method is a setter method that takes in the file that contains
    the information for Classic object and it sets the variables for the object
 
    Pre-Condition:
    ifstream &file - Represents the file that we are wanting to read from
 
    Post Condition:
    Sets the data from the file to the Classic object
----------------------------------------------------------------------------*/
void Classic::setData(ifstream &file)
{
    int stock, releaseMonth, releaseYear;
    string director, title, firstName, lastName;
    
    file.ignore(1);
    file >> stock;
    file.ignore(2);
    getline(file, director, ',');
    file.ignore(1);
    getline(file, title, ',');
    file >> firstName >> lastName >> releaseMonth >> releaseYear;
    
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor((firstName + " " + lastName));
    setReleaseMonth(releaseMonth);
    setReleaseYear(releaseYear);
}
/*----------------------------setMajorActor----------------------------------
 setMajorActor:
    This is a setter method that sets the major actor for the Classic object.
    Pre-Conditions:
    string majorActor - represents the major actor's name for the movie.
 
    Post Condition:
    Sets the major actor to the parameter passed in.
----------------------------------------------------------------------------*/
void Classic::setMajorActor(string majorActor)
{
    this->majorActor = majorActor;
}
/*------------------------------getMajorActor--------------------------------
 getMajorActor:
    This is a getter method that returns the major actors name for the
    Classic object.
----------------------------------------------------------------------------*/
string Classic::getMajorActor()const
{
    return this->majorActor;
}
/*-------------------------------setReleaseMonth-----------------------------
 setReleaseMonth:
    This is a setter method that sets the releaseMonth of the Classic object.
    Pre-Conditions:
    int month - represents the release month of the Classic object.
 
    Post Condition:
    Sets the release month to the parameter passed in.
----------------------------------------------------------------------------*/
bool Classic::setReleaseMonth(int month)
{
    //if the month is out of range
    if(month < 1 || month >= 13)
    {
        //Inform the business of the invalid month
        cerr << "ERROR: Invalid month " << month << endl;
        return false;
    }
    
    this->releaseMonth = month;
    return true;
}
/*--------------------------------getReleaseMonth----------------------------
 getReleaseMonth:
    This is a getter method that returns the release month for the Classic object.
----------------------------------------------------------------------------*/
int Classic::getReleaseMonth()const
{
    return this->releaseMonth;
}
/*-------------------------------operator==-----------------------------------
 operator==:
    This is an == operator overload that compares the current Classic movie
    to another Classic movie.
    Pre-Condition:
    Movie &cla - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Classic movies are equal or not
----------------------------------------------------------------------------*/
bool Classic::operator==(const Movie& cla)const
{
    //If both stocks are the same
    if(getStock() == cla.getStock())
    {
        //If both directors are the same
        if(getDirector().compare(cla.getDirector()) == 0)
        {
            //If both titles are the same
            if(getTitle().compare(cla.getTitle()) == 0)
            {
                //If both release months are the same
                if(getReleaseMonth() == cla.getReleaseMonth())
                {
                    //If both release years are the same
                    if(getReleaseYear() == cla.getReleaseYear())
                    {
                        //If both major actors are the same
                        if(getMajorActor().compare(cla.getMajorActor()) == 0)
                        {
                            //Return true if all the variables are equal
                            return true;
                        }
                    }
                }
            }
        }
    }
    //Return false if one of the variables are different
    return false;
}
/*------------------------------operator!=-----------------------------------
 operator!=:
    This is an != operator overload that compares the current Classic movie
    to another Classic movie.
    Pre-Condition:
    Movie &cla - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the Classic movies are not equal.
----------------------------------------------------------------------------*/
bool Classic::operator!=(const Movie& cla)const
{
     return !(*this == cla);
}
/*-------------------------------operator>-----------------------------------
 operator>:
    This is a > operator overload that checks to see if the current Classic
    movie is greater than the other Classic
    Pre-Condition:
    Movie &cla - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Classic movies is greater than the other
    Classic object.
----------------------------------------------------------------------------*/
bool Classic::operator>(const Movie& cla) const
{
    //If the current release year is greater than the other movie
    if (getReleaseYear() > cla.getReleaseYear())
    {
        //Return true
        return true;
    }
    //Otherwise, check to see if the current release year is equal to the other movie
    else if (getReleaseYear() == cla.getReleaseYear())
    {
        //If so, check the release months and see if the current month is greater
        if (getReleaseMonth() > cla.getReleaseMonth())
        {
            //If so, return true
            return true;
        }
        //Otherwise, check the release months and see if they are equal
        else if (getReleaseMonth() == cla.getReleaseMonth())
        {
            //If equal, compare the major actor's names
            if (getMajorActor().compare(cla.getMajorActor()) > 0)
            {
                //Return true if the current Classic is greater than the other one
                return true;
            }
            else
            {
                //Return false if the current major actor is less than the other one
                return false;
            }
        }
        else
        {
            //Return false if the current release month is less
            return false;
        }
    }
    else
    {
        //Return false if the current release year is less
        return false;
    }
}
/*-------------------------------operator<-----------------------------------
 operator<:
    This is a < operator overload that checks to see if the current Classic
    movie is less than the other Classic
    Pre-Condition:
    Movie &cla - Represents the movie that we want to compare to
 
    Post Condition:
    Returns whether or not the current Classic movies is less than the other
    Classic object.
----------------------------------------------------------------------------*/
bool Classic::operator<(const Movie& cla) const
{
    //If the current release year is less than the other movie
     if (getReleaseYear() < cla.getReleaseYear())
     {
         //Return true
         return true;
     }
    //Otherwise, check to see if the current release year is equal to the other movie
     else if (getReleaseYear() == cla.getReleaseYear())
     {
         //If so, check the release months and see if the current month is less
         if (getReleaseMonth() < cla.getReleaseMonth())
         {
             //If so, return true
             return true;
         }
         //Otherwise, check the release months and see if they are equal
         else if (getReleaseMonth() == cla.getReleaseMonth())
         {
             //If equal, compare the major actor's names
             if (getMajorActor().compare(cla.getMajorActor()) < 0)
             {
                 //Return true if the current Classic is less than the other one
                 return true;
             }
             else
             {
                 //Return false if the current major actor is greater than the other one
                 return false;
             }
         }
         else
         {
             //Return false if the current release month is greater
             return false;
         }
     }
     else
     {
         //Return false if the current release year is greater
         return false;
     }
}
/*---------------------------------operator=---------------------------------
 operator=:
    This is an = operator overload that creates a copy of another Classic object
    and establishes the information to the current Classic object.
    Pre-Condition:
    Movie &c - Represents the movie that we want to copy information from
 
    Post Condition:
    Returns a copy of the movie that was passed in and assigns it to the
    current Classic object
----------------------------------------------------------------------------*/
Movie* Classic::operator=(const Movie &c)
{
    //Replaces the current Classic movie
    //with new information from a different movie
    setStock(c.getStock());
    setDirector(c.getDirector());
    setTitle(c.getTitle());
    setMajorActor(c.getMajorActor());
    setReleaseMonth(c.getReleaseMonth());
    setReleaseYear(c.getReleaseYear());
    
    return this;
}
/*-----------------------------------display---------------------------------
 display:
    This method displays the contents of the Classic object.
----------------------------------------------------------------------------*/
void Classic::display()
{
    //Displays the Classic movie object's credentials
    cout << getMovieType() << ", " << getStock()
    << ", " << getDirector() << ", " << getTitle()
    << ", " << getMajorActor() << " " << getReleaseMonth()
    << " " << getReleaseYear() << endl;
}
