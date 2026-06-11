================================
VEHICLE RENTAL MANAGEMENT SYSTEM
================================

PROJECT DESCRIPTION
This is a console based Vehicle Rental Management System that uses C++ and Qt6(Qt Core). It uses OOP principles, menu driven interaction, file handling and rental/return state management.


HOW TO OPEN THE PROJECT
1 Open Qt Creator
2 Click open File or project
3 Navigate to the assignment folder 21097305A1
4 Select CMakeLists.txt
5 Click open
6 Qt Creator will open a page saying "Configure Project"
7 Click configure project



HOW TO BUILD PROJECT
1 Go to build in the ribbon at the top of the page
2 click build project "Vehicle Rental"
  (This creates the build folder with the .exe file)
3 Go to the assignment folder in file explorer
4 move the text file vehicles.txt to the compiler folder located in the build folder (This is the same folder that contains the compiled Vehicle_Rental.exe file)
Example Path: build\Desktop_Qt_6_11_0_MinGW_64_bit-Debug\Vehicle_Rental.exe


HOW TO RUN PROJECT
1 go to projects in the left bar
2 go to run settings
3 tick run in terminal
4 Go to debug
5 Then press run


DATA FILE
Included in the assignment folder 21097305A1, is the vehicles.txt file which contains vehicle information using pipe-separation.
File Format:
	Car|ID|Brand|Model|PricePerDay|IsRented|Doors|Seats
   	Motorcycle|ID|Brand|Model|PricePerDay|IsRented|EngineCC
Example:
   	Car|C001|Toyota|Corolla|350.00|false|4|5
	Motorcycle|M001|Yamaha|MT-07|200.00|false|689

MENU OPTIONS
-------------------
The menu includes the following options 


1. Add Vehicle      - Add a new Car or Motorcycle
2. Search by ID     - Search for a vehicle using its ID
3. Display All      - Display all vehicles in the system
4. Display Available- Display only available vehicles
5. Rent Vehicle     - Rent a vehicle by ID
6. Return Vehicle   - Return a rented vehicle by ID
7. Exit             - Save all changes and exit


STUDENT INFORMATION
-------------------
Name: Shazana Sardiwalla
Student Number: 21097305
Module: COS2614
Assignment: 1

EXTRA NOTE:
-------------------
Please note that the folder is named using the format StudentNumber_AssignmentNumber

My student number, name and assignment number is also included in main.cpp

I have also included a pdf containing screenshots of the working project with captions

