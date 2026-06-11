#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

//include base class header file
#include "vehicle.h"

class Motorcycle : public Vehicle
{
public:
    //============
    // GETTER
    //============
    int getEngineCapacity() const ;

    //============
    // SETTER
    //============
    void setEngineCapacity(int capacity) ;

    //======================
    // THE VIRTUAL FUNCTIONS
    //======================
    QString typeName() const override ;
    QString displayInfo() const override ;
    QString toFileString() const override;

    //============
    // CONSTRUCTOR
    //============
    Motorcycle();

    //============
    // DESTRUCTOR
    //============
    ~Motorcycle() ;

private:
    int engineCapacityCC ;
};

#endif // MOTORCYCLE_H
