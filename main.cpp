//Name: Shazana Sardiwalla
//Student Number: 21097305
//Assignment 1

#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QList>

//include the class headers
#include "car.h"
#include "motorcycle.h"


//======================
// DISPLAY MENU FUNCTION
//======================
void displayMenu() {
    //displays the menu in a number format
    QTextStream out(stdout);
    out << "================================\n" ;
    out << "Vehicle Rental Management System\n" ;
    out << "================================\n" ;
    out << "Main Menu\n" ;
    out << "1. Add Vehicle\n" ;
    out << "2. Search Vehicle by ID\n" ;
    out << "3. Display all vehicles\n" ;
    out << "4. Display available vehicles only\n" ;
    out << "5. Rent vehicle\n" ;
    out << "6. Return vehicle\n" ;
    out << "7. Exit\n" ;
    out << "Please choose an option (1-7)\n" ;
    out.flush();
}

//=========================
// LOAD FROM FILE FUNCTION
//=========================
void loadFromFile(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);

    //Open File
    QFile file("vehicles.txt") ;

    //check if file is open for reading
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        console << "Could not open file.\n";
        console.flush();
        return ;
    }

    //read from file line by line
    QTextStream in(&file) ;
    while(!in.atEnd()) {
        //while not end of file read the current line
        QString line = in.readLine();

        //seperate each part based off the partitions
        QStringList parts = line.split("|");

        //check the first part for vehicle type
        //if car then
        if(parts[0] == "Car") {

            //create car object
            Car* car = new Car();

            //use setters to set variables
            car->setId(parts[1]);
            car->setBrand(parts[2]);
            car->setModel(parts[3]);
            car->setPricePerDay(parts[4].toDouble());
            car->setIsRented(parts[5] == "true");
            car->setNumberOfDoors(parts[6].toInt());
            car->setNumberOfSeats(parts[7].toInt());

            //add object to list
            vehicles.append(car);

        }
        // if motorcycle then
        else if(parts[0] == "Motorcycle") {
            //create motorcycle object
            Motorcycle* motorcycle = new Motorcycle();

            //use setters to set variables
            motorcycle->setId(parts[1]);
            motorcycle->setBrand(parts[2]);
            motorcycle->setModel(parts[3]);
            motorcycle->setPricePerDay(parts[4].toDouble());
            motorcycle->setIsRented(parts[5] == "true");
            motorcycle->setEngineCapacity(parts[6].toInt());

            //add to list
            vehicles.append(motorcycle);
        }
    }

    //close the file
    file.close();
}


//======================
// SAVE TO FILE FUNCTION
//======================
void saveToFile(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);

    //open file
    QFile file("vehicles.txt") ;

    //check if file is open for writing
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        console << "Could not open file.\n" ;
        console.flush();
        return ;
    }

    //write the temp list to the file
    QTextStream out(&file);
    for(Vehicle* v : vehicles) {
        out << v->toFileString() << "\n" ;
    }

    //close the file
    file.close();
}

//========================
// SEARCH VEHICLE FUNCTION
//========================
void searchVehicle(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);
    QTextStream input(stdin);

    //displays heading for this section
    console << "================================\n" ;
    console << "      SEARCH VEHICLE BY ID      \n" ;
    console << "================================\n" ;
    console << "Enter vehicle ID: ";
    console.flush();

    //ask user for id
    QString id = input.readLine();

    //check if id is empty
    if(id.isEmpty()) {
        console << "ID cannot be empty.\n";
        console << "\n" ;
        console.flush();
        return;
    }

    //create empty pointer
    Vehicle* found = nullptr;

    //use pointer to point to the current
    //vehicle in the the list
    for(Vehicle* v : vehicles) {

        //check if user id matches an id from list
        if(v->getId() == id) {
            found = v;
            break;
        }
    }

    //if not found displays error
    if(found == nullptr) {
        console << "Vehicle not found.\n";
        console << "\n" ;
        console.flush();
    } else {

        //if found displays vehicle info
        console << found->displayInfo();
        console << "\n" ;
    }
}


//=====================
// ADD VEHICLE FUNCTION
//=====================
void addVehicle(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);
    QTextStream input(stdin);

    //temp variables
    QString id ;
    QString brand ;
    QString model ;
    double price ;
    bool rented ;
    int numDoors ;
    int numSeats ;
    int engineCap ;

    //displays heading and choose which vehicle type
    console << "================================\n" ;
    console << "          ADD VEHICLE           \n" ;
    console << "================================\n" ;
    console << "Enter the vehicle type:\n" ;
    console << "1. Car\n" ;
    console << "2. Motorcycle\n" ;
    console.flush();

    //check the type
    int type = input.readLine().toInt();
    if (type == 1) {

        //if 1 add car details
        console << "================================\n" ;
        console << "        ADD CAR DETAILS         \n" ;
        console << "================================\n" ;
        console << "Enter id: " ;
        console.flush();
        id = input.readLine();

        //check if id is empty give an error
        if(id.isEmpty()) {
            console << "The ID cannot be empty.\n";
            console << "\n" ;
            console.flush();
            return ;
        }

        //check for duplicates
        for(Vehicle* v : vehicles) {
            if(v->getId() == id) {
                console << "ID already exists. Vehicle cannot be added.\n";
                console << "\n" ;
                console.flush();
                return;
            }
        }

        //get the user info about new car
        //and store in temp variables
        console << "Enter the car brand: " ;
        console.flush();
        brand = input.readLine() ;

        console << "Enter the car model: " ;
        console.flush();
        model = input.readLine() ;

        console << "Enter the car price per day: " ;
        console.flush();
        price = input.readLine().toDouble() ;

        console << "Is the car rented? [Y/N]: " ;
        console.flush();

        //for rented if y then true else false
        QString rentedInput = input.readLine() ;
        if (rentedInput == "Y" || rentedInput == "y")
            rented = true ;
        else
            rented = false;

        console <<"How many doors does the car have: ";
        console.flush();
        numDoors = input.readLine().toInt();

        console << "How many seats does the car have: " ;
        console.flush();
        numSeats = input.readLine().toInt();

        //create car object
        Car* car = new Car() ;

        //use the setters to store new vehicle info
        car->setId(id);
        car->setBrand(brand);
        car->setModel(model);
        car->setPricePerDay(price);
        car->setIsRented(rented);
        car->setNumberOfDoors(numDoors);
        car->setNumberOfSeats(numSeats);

        //add to vehicles list
        vehicles.append(car);

        //display success message
        console << "\nCar added successfully.\n" ;
        console << "\n" ;
        console.flush();

    }
    else if(type == 2) {
        //if 2 add motorcycle details

        //displays heading for motorcycle details
        console << "================================\n" ;
        console << "     ADD MOTORCYCLE DETAILS     \n" ;
        console << "================================\n" ;
        console << "Enter id: " ;
        console.flush();
        id = input.readLine();

        //check if id is empty
        if(id.isEmpty()) {
            console << "The ID cannot be empty.\n";
            console << "\n";
            console.flush();
            return ;
        }


        //check for duplicates
        for(Vehicle* v : vehicles) {
            if(v->getId() == id) {
                console << "ID already exists. Vehicle cannot be added.\n";
                console << "\n" ;
                console.flush();
                return;
            }
        }

        //get the user info about new vehicle
        //and store in temp variables
        console << "Enter the motorcycle brand: " ;
        console.flush();
        brand = input.readLine() ;

        console << "Enter the motorcycle model: " ;
        console.flush();
        model = input.readLine() ;

        console << "Enter the motorcycle price per day: " ;
        console.flush();
        price = input.readLine().toDouble() ;

        console << "Is the motorcycle rented? [Y/N]: " ;
        console.flush();

        //if rented y is true else false
        QString rentedInput = input.readLine() ;
        if (rentedInput == "Y" || rentedInput == "y")
            rented = true ;
        else
            rented = false;

        console <<"How much is the engine capacity (CC): ";
        console.flush();
        engineCap = input.readLine().toInt();

        //create motorcycle object
        Motorcycle* motorcycle = new Motorcycle() ;

        //use the setters to store new info
        motorcycle->setId(id);
        motorcycle->setBrand(brand);
        motorcycle->setModel(model);
        motorcycle->setPricePerDay(price);
        motorcycle->setIsRented(rented);
        motorcycle->setEngineCapacity(engineCap);

        //add to vehicles list
        vehicles.append(motorcycle);

        //display success message
        console << "\nMotorcycle added successfully.\n" ;
        console << "\n" ;
        console.flush();
    }


}

//======================
// RENT VEHICLE FUNCTION
//======================
void rentVehicle(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);
    QTextStream input(stdin) ;

    //ask user for id and display heading
    console << "================================\n" ;
    console << "         RENT VEHICLE           \n" ;
    console << "================================\n" ;
    console << "Enter the vehicle id: " ;
    console.flush();

    QString searchId = input.readLine() ;

    //create empty pointer
    Vehicle* found = nullptr;

    //user pointer to loop through the vehicle list
    for(Vehicle* v : vehicles) {

        //check for matching id
        if(v->getId() == searchId)
            found = v ;
    }

    //if vehicle not found display error message
    if (found == nullptr) {
        console << "Vehicle with id " << searchId << " does not exist.\n" ;
        console << "\n" ;
        console.flush();
    }
    else {
        //if found but rented display error message
        if(found->getIsRented() == true) {
            console << "Vehicle is unavailable for renting.\n";
            console << "\n" ;
            console.flush();
        }
        else {
            //if found and available, set to rented and display
            //succes message
            found->setIsRented(true) ;
            console << "Vehicle has been successfully rented.\n";
            console << "\n" ;
            console.flush();
        }
    }
}


//========================
// RETURN VEHICLE FUNCTION
//========================
void returnVehicle(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);
    QTextStream input(stdin) ;

    //ask user for id and display heading
    console << "================================\n" ;
    console << "         RETURN VEHICLE         \n" ;
    console << "================================\n" ;
    console << "Enter the vehicle id: " ;
    console.flush();

    QString searchId = input.readLine() ;

    //create empty pointer
    Vehicle* found = nullptr;

    //user pointer to loop through the vehicle list
    for(Vehicle* v : vehicles) {

        //check for matching id
        if(v->getId() == searchId)
            found = v ;
    }

    //if vehicle not found display error message
    if(found == nullptr) {
        console << "Vehicle with id " << searchId << " does not exist.\n" ;
        console << "\n" ;
        console.flush();
    }
    else {
        //if found but available display error message
        if(found->getIsRented() == false) {
            console << "Vehicle is available and cannot be returned.\n" ;
            console << "\n" ;
            console.flush();
        }
        else {
            //if found but not available, set to returned
            // and display success message
            found->setIsRented(false) ;
            console << "Vehicle has been returned.\n";
            console << "\n" ;
            console.flush();
        }
    }

}


//=====================
// DISPLAY ALL FUNCTION
//=====================
void displayAll(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout);

    // check if list is empty
    if(vehicles.isEmpty()) {
        console << "No vehicles available.\n";
        console << "\n" ;
        console.flush();
        return;
    }

    //display heading
    console << "================================\n" ;
    console << "          ALL VEHICLES          \n" ;
    console << "================================\n" ;
    console.flush();

    // loop through all vehicles in list and display the info
    for(Vehicle* v : vehicles) {
        console << "Type: " << v->typeName() << "\n";
        console << v->displayInfo();
        console << "--------------------------------\n" ;
        console << "\n" ;
        console.flush();
    }
}

//===========================
// DISPLAY AVAILABLE FUNCTION
//===========================
void displayAvailable(QList<Vehicle*>& vehicles) {
    QTextStream console(stdout) ;

    // check if list is empty
    if(vehicles.isEmpty()) {
        console << "No vehicles available.\n";
        console << "\n" ;
        console.flush();
        return;
    }

    //display heading
    console << "================================\n" ;
    console << "      AVAILABLE VEHICLES        \n" ;
    console << "================================\n" ;
    console.flush();

    int count = 0;

    //loop through all vehicles if not rented display info
    for(Vehicle* v : vehicles) {
        if(v->getIsRented() == false){
            count++ ;
            console << v->displayInfo() << "\n" ;
            console << "--------------------------------\n" ;
        }
    }

    //if all vehicles are rented display error
    if (count == 0) {
        console << "No vehicles are available.\n" ;
        console << "\n" ;
        console.flush();
    }

}


//==============
// MAIN FUNCTION
//==============
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //declare input and output stream
    QTextStream in(stdin);
    QTextStream out(stdout);

    //create list for temp storage and editing of vehicle file
    QList<Vehicle*> vehicles ;

    //call loadfromfile function and open the file
    loadFromFile(vehicles);


    //console interface
    while(true) {

        //display the main menu
        displayMenu();

        //read the users choice
        int choice = in.readLine().toInt() ;
        out << "\n" << Qt::flush ;

        //determine the choice using switch
        switch(choice)
        {
        case 1:
            //add vehicle
            addVehicle(vehicles);
            break ;

        case 2:
            //search vehicle by id
            searchVehicle(vehicles);
            break ;

        case 3:
            //display all vehicles
            displayAll(vehicles) ;
            break ;
        case 4:
            //display available vehicles only
            displayAvailable(vehicles) ;
            break ;

        case 5:
            //rent vehicle
            rentVehicle(vehicles);
            break ;

        case 6:
            //return vehicle
            returnVehicle(vehicles);
            break ;

        case 7:
            //save all vehicles to file and exit program
            saveToFile(vehicles);
            for(int i = 0; i < vehicles.size(); i++) {
                delete vehicles[i];
            }
            vehicles.clear();
            out << "All changes saved.\n" ;
            out << "================================\n" ;
            out << " THANK YOU FOR USING OUR SYSTEM \n" ;
            out << "================================\n" ;
            return 0;

        default :
            //if invalid choice is made loops until valid choice is made
            out << "Invalid choice.\n" ;
            out << "\n" ;
            out.flush();
            break ;

        }//end switch

    }//end while


    return 0;
}

