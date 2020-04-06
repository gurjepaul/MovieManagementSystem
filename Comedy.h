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

#ifndef Comedy_h
#define Comedy_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
    //Constructors
    Comedy();
    Comedy(int stock, string director, string title, int releaseYear);
    ~Comedy();
    
    //Setter
    void setData(ifstream &file);
    
    void display();
    
    //Operator overloads
    bool operator==(const Movie& d) const;
    bool operator!=(const Movie& d) const;
    bool operator>(const Movie& d) const;
    bool operator<(const Movie& d) const;
    Movie* operator=(const Movie& d);
};
#endif /* Comedy_h */
