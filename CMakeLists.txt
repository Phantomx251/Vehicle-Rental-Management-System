cmake_minimum_required(VERSION 3.19)
project(Vehicle_Rental LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Vehicle_Rental
    main.cpp
    vehicle.h vehicle.cpp
    car.h car.cpp
    motorcycle.h motorcycle.cpp
)

target_link_libraries(Vehicle_Rental
    PRIVATE
        Qt::Core
)

install(TARGETS Vehicle_Rental
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
