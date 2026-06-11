#ifndef CAR_H
#define CAR_H

//include base class header
#include "vehicle.h"

class Car : public Vehicle
{
public:

    //==========
    // GETTERS
    //==========
    int getNumberOfDoors() const ;
    int getNumberOfSeats() const ;

    //==========
    // SETTERS
    //==========
    void setNumberOfDoors(int numDoors) ;
    void setNumberOfSeats(int numSeats) ;

    //======================
    // THE VIRTUAL FUNCTIONS
    //======================
    QString typeName() const override ;
    QString displayInfo() const override ;
    QString toFileString() const override ;

    //============
    // CONSTRUCTOR
    //============
    Car();

    //============
    // DESTRUCTOR
    //============
    ~Car();

private:
    int numberOfDoors ;
    int numberOfSeats ;
};

#endif // CAR_H
