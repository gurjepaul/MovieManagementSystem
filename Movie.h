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
#ifndef Movie_h
#define Movie_h

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Movie
{
public:
    // Constructors
    Movie();
    Movie(char movieType, int stock, string director, string title, int releaseYear);
    ~Movie();
    
    // Setters
    virtual void setData(ifstream &file);
    virtual void setMovieType(char movieType);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setReleaseYear(int releaseYear);
    
    virtual void setMajorActor(string majorActor);
    virtual bool setReleaseMonth(int month);
    
    // Getters
    virtual char getMovieType() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const;
    virtual int getReleaseYear( )const;
    
    virtual string getMajorActor()const;
    virtual int getReleaseMonth()const;
    
    //Methods that change the stock of a movie
    virtual bool increaseStock();
    virtual bool decreaseStock();
    
    //Operator overloads
    virtual bool operator==(const Movie& c)const = 0;
    virtual bool operator!=(const Movie& c)const = 0;
    virtual bool operator>(const Movie& c)const = 0;
    virtual bool operator<(const Movie& c)const = 0;
    virtual Movie* operator=(const Movie& c);

    //Displays the informations of a movie object
    virtual void display()const;
    
protected:
    char movieType;
    int stock;
    string director;
    string title;
    int releaseYear;

};

#endif /* Movie_h */
