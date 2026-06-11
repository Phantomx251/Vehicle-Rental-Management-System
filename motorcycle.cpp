//include the header file
#include "motorcycle.h"


//======================
// GETTER IMPLEMENTATION
//======================
int Motorcycle::getEngineCapacity() const {
    return engineCapacityCC ;
}

//======================
// SETTER IMPLEMENTATION
//======================
void Motorcycle::setEngineCapacity(int capacity) {
    engineCapacityCC = capacity ;
}

//==================================
// CVIRTUAL FUNCTIONS IMPLEMENTATION
//==================================
QString Motorcycle::typeName() const {
    //return vehicle type
    return "Motorcycle" ;
}

QString Motorcycle::displayInfo() const {
    //overrieded diplay
    QString info = Vehicle::displayInfo() ;
    info += "Engine Capacity (CC): " + QString::number(getEngineCapacity()) + "\n" ;
    return info ;
}

QString Motorcycle::toFileString() const {
    //creates the format for the savetofile function
    return "Motorcycle|" + getId() + "|" + getBrand() + "|" +
           getModel() + "|" + QString::number(getPricePerDay()) + "|" +
           QString(getIsRented() ? "true" : "false") + "|" +
           QString::number(getEngineCapacity()) ;

}

//===========================
// CONSTRUCTOR IMPLEMENTATION
//===========================
Motorcycle::Motorcycle() {
    engineCapacityCC = 0 ;
}

//==========================
// DESTRUCTOR IMPLEMENTATION
//==========================
Motorcycle::~Motorcycle() {

}
