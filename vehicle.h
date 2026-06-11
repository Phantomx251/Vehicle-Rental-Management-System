#ifndef VEHICLE_H
#define VEHICLE_H

//declare the headers needed
#include <QString>

//declare the abstract base class
class Vehicle
{
    public:
        //======================
        // THE VIRTUAL FUNCTIONS
        //======================
        //virtual functions for getting the vehicle
        //type and displaying the info
        virtual QString typeName() const = 0;
        virtual QString displayInfo() const;

        //to access car/motorcycle specific methods
        //and to format the save to file
        virtual QString toFileString() const = 0;

        //============
        // GETTERS
        //============
        QString getId() const;
        QString getBrand() const;
        QString getModel() const;
        double getPricePerDay() const;
        bool getIsRented() const;

        //============
        // SETTERS
        //============
        void setId(QString idValue) ;
        void setBrand(QString brandValue) ;
        void setModel(QString modelValue) ;
        void setPricePerDay(double priceValue) ;
        void setIsRented(bool rentedValue) ;


        //============
        // CONSTRUCTOR
        //============
        Vehicle();

        //============
        // DESTRUCTOR
        //============
        virtual ~Vehicle();

    private:
        QString id;
        QString brand;
        QString model;
        double pricePerDay;
        bool isRented;

};

#endif // VEHICLE_H
