//include the header file
#include "car.h"

//=======================
// GETTERS IMPLEMENTATION
//=======================
int Car::getNumberOfDoors() const {
    return numberOfDoors ;
}

int Car::getNumberOfSeats() const {
    return numberOfSeats ;
}

//=======================
// SETTERS IMPLEMENTATION
//=======================
void Car::setNumberOfDoors(int numDoors) {
    numberOfDoors = numDoors ;
}

void Car::setNumberOfSeats(int numSeats) {
    numberOfSeats = numSeats ;
}

//=================================
// VIRTUAL FUNCTIONS IMPLEMENTATION
//=================================
QString Car::typeName() const {
    //returns vehicle type
    return "Car" ;
}

QString Car::displayInfo() const {
    //override and display the derived info
    QString info = Vehicle::displayInfo() ;
    info += "Number of Doors: " + QString::number(getNumberOfDoors()) + "\n" ;
    info += "Number of Seats: " + QString::number(getNumberOfSeats()) + "\n" ;
    return info ;
}

QString Car::toFileString() const {
    //creates a format for the save to file
    return "Car|" + getId() + "|" + getBrand() + "|" + getModel() +
           "|" + QString::number(getPricePerDay()) + "|" +
           QString(getIsRented() ? "true" : "false") + "|" +
           QString::number(getNumberOfDoors()) + "|" +
           QString::number(getNumberOfSeats()) ;
}

//===========================
// CONSTRUCTOR IMPLEMENTATION
//===========================
Car::Car() {
    numberOfDoors = 0 ;
    numberOfSeats = 0 ;
}

//==========================
// DESTRUCTOR IMPLEMENTATION
//==========================
Car::~Car() {

}