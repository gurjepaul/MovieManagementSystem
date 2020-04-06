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

#ifndef Drama_h
#define Drama_h

#include <string>
#include <fstream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
    //Constructors
    Drama();
    Drama(int stock, string director, string title, int releaseYear);
    ~Drama();
    
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
#endif /* Drama_h */
