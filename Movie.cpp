/*------------------------------------------------------------------------------
Authors: Jay Brar & Jose Palomera
CSS 343 Section C Wooyoung Kim
Due Date: March 14, 2020
Class Movie
Description:
    The Movie class is made to represent a basic movie and all the pieces
    of data that includes with it. This class contains details like the
    stock, the director's name, the title, the release date and etc.
    This Movie class is also the parent class of the subclasses Classic,
    Comedy, and Drama.
------------------------------------------------------------------------------*/

#include <stdio.h>
#include "Movie.h"

/*-------------------------------Movie--------------------------------------
Movie:
 
    This is a basic constructor that sets the movie type to M and creates a
    new Movie object
----------------------------------------------------------------------------*/
Movie::Movie()
{
    setMovieType('M');
}

/*--------------------------------Movie--------------------------------------
Movie:
    This is a basic constructor that sets the variables from the parameters
    given to the method.
    Pre-Condition:
    char movieType - Represents the movie type of the Movie object
    int stock - Represents the amount of movies the object has
    string director - Represents the directors name
    string title - Represents the title of the movie
    int releaseYear - Represents the release year of the movie
 
    Post Condition:
    Sets the variables to the values of the parameters
----------------------------------------------------------------------------*/
Movie::Movie(char movieType, int stock, string director, string title, int releaseYear)
{
    setMovieType(movieType);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(releaseYear);
}

/*--------------------------------~Movie-------------------------------------
~Movie:
    This is a basic destructor for the Movie object
----------------------------------------------------------------------------*/
Movie::~Movie(){}

/*--------------------------------setData------------------------------------
setData:
    This method is a setter method that takes in the file that contains
    the information for Movie object and it sets the variables for the object
 
    Pre-Condition:
    ifstream &file - Represents the file that we are wanting to read from
 
    Post Condition:
    Sets the data from the file to the movie object
----------------------------------------------------------------------------*/
void Movie::setData(ifstream &file)
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

/*------------------------------setMovieType---------------------------------
setMovieType:
    This is a setter method that sets the movie type to the movie object.
    Pre-Conditions:
    char movieType - represents the type of movie the Movie object is.
 
    Post Condition:
    Sets the movie type to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setMovieType(char movieType)
{
    this->movieType = movieType;
}

/*------------------------------setStock--------------------------------------
 setStock:
    This is a setter method that sets the stock of the movie object.
    Pre-Conditions:
    int stock - represents the stock the movie object will have.
 
    Post Condition:
    Sets the stock to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setStock(int stock)
{
    this->stock = stock;
}

/*------------------------------setDirector-----------------------------------
 setDirector:
    This is a setter method that sets the director for to the movie object.
    Pre-Conditions:
    string director - represents the directors name for the movie.
 
    Post Condition:
    Sets the director to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setDirector(string director)
{
    this->director = director;
}

/*------------------------------setTitle--------------------------------------
 setTitle:
    This is a setter method that sets the title for to the movie object.
    Pre-Conditions:
    string title - represents the title name for the movie.
 
    Post Condition:
    Sets the title to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setTitle(string title)
{
    this->title = title;
}

/*------------------------------setReleaseYear--------------------------------
 setReleaseYear:
    This is a setter method that sets the releaseYear of the movie object.
    Pre-Conditions:
    int releaseYear - represents the releaseYear of the movie.
 
    Post Condition:
    Sets the release year to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

/*------------------------------setMajorActor---------------------------------
 setMajorActor:
    This is a setter method that sets the major actor for the movie object.
    Pre-Conditions:
    string majorActor - represents the major actor's name for the movie.
 
    Post Condition:
    Sets the major actor to the parameter passed in.
----------------------------------------------------------------------------*/
void Movie::setMajorActor(string majorActor){}

/*-------------------------------setReleaseMonth-----------------------------
 setReleaseMonth:
    This is a setter method that sets the releaseMonth of the movie object.
    Pre-Conditions:
    int releaseMonth - represents the releaseMonth of the movie object.
 
    Post Condition:
    Sets the release month to the parameter passed in.
----------------------------------------------------------------------------*/
bool Movie::setReleaseMonth(int month)
{
    //If the month is out of the range
    if(month < 1 || month >= 13)
    {
        //Inform the business of the invalid month
        cerr << "ERROR: Invalid month" <<endl;
        return false;
    }
    
    return true;
}

/*------------------------------getMovieType---------------------------------
getMovieType:
    This is a getter method that returns the movie type for the movie object.
----------------------------------------------------------------------------*/
char Movie::getMovieType() const
{
    return movieType;
}

/*-------------------------------getStock------------------------------------
 getStock:
    This is a getter method that returns the stock for the movie object.
----------------------------------------------------------------------------*/
int Movie::getStock() const
{
    return stock;
}

/*-------------------------------getDirector---------------------------------
 getDirector:
    This is a getter method that returns the directors name for the movie object.
----------------------------------------------------------------------------*/
string Movie::getDirector() const
{
    return director;
}

/*-------------------------------getTitle------------------------------------
 getTitle:
    This is a getter method that returns the title for the movie object.
----------------------------------------------------------------------------*/
string Movie::getTitle() const
{
    return title;
}

/*-------------------------------getReleaseYear------------------------------
 getReleaseYear:
    This is a getter method that returns the release year for the movie object.
----------------------------------------------------------------------------*/
int Movie::getReleaseYear( )const
{
    return releaseYear;
}

/*--------------------------------getMajorActor------------------------------
 getMajorActor:
    This is a getter method that returns the major actors name for the movie object.
----------------------------------------------------------------------------*/
string Movie::getMajorActor()const
{
    return NULL;
}

/*--------------------------------getReleaseMonth-----------------------------
 getReleaseMonth:
    This is a getter method that returns the release month for the movie object.
----------------------------------------------------------------------------*/
int Movie::getReleaseMonth()const
{
    return NULL;
}

/*------------------------------increaseStock--------------------------------
increaseStock:
    This method increases the stock of the current Movie object by 1.
----------------------------------------------------------------------------*/
bool Movie::increaseStock()
{
    //Increases the stock of a movie by 1
    stock++;
    return true;
}

/*--------------------------------decreaseStock-------------------------------
decreaseStock:
    This method decreases the stock of the current Movie object by 1.
----------------------------------------------------------------------------*/
bool Movie::decreaseStock()
{
    //Checks to see if the movie is able to decrease stock
    if(stock == 0)
    {
        return false;
    }
    
    //If yes, then the stock decreases by 1
    stock--;
    return true;
}

/*-------------------------------operator=-----------------------------------
operator=:
    This is an = operator overload that creates a copy of another Movie object
    and establishes the information to the current Movie object.
    Pre-Condition:
    Movie &c - Represents the movie that we want to copy information from
 
    Post Condition:
    Returns a copy of the movie that was passed in and assigns it to the
    current Movie object
----------------------------------------------------------------------------*/
Movie* Movie::operator=(const Movie &c)
{
    return this;
}

void Movie::display()const
{
    //Displays the movie's credentials
    cout << getMovieType() << ", " << getStock() << ", " << getDirector()
    << ", " << getTitle() << ", " << getReleaseYear() << endl;
}
