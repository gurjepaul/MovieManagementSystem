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

#ifndef Classic_h
#define Classic_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
    //Constructors
    Classic();
    Classic(int stock, string director, string title, string majorActor,int releaseMonth, int releaseYear);
    ~Classic();
    
    //Setters
    void setData(ifstream &file);
    void setMajorActor(string majorActor);
    bool setReleaseMonth(int month);
    
    //Getters
    string getMajorActor()const;
    int getReleaseMonth()const;
    
    void display();
    
    //Operator overloads
    bool operator==(const Movie& c) const;
    bool operator!=(const Movie& c) const;
    bool operator>(const Movie& c) const;
    bool operator<(const Movie& c) const;
    Movie* operator=(const Movie& c);
    
private:
    //Variables that store the additional information a Classic
    //movie object has
    string majorActor;
    int releaseMonth;
    
};

#endif /* Classic_h */
