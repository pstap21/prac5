#include <iostream>
#include <string>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot lot(10);
    int currentID = 1;

    std::cout << "Welcome to the Parking lot.\n";

    while (lot.getCount() < 10) {
        std::string type;
        std::cout << "Please enter type of vehicle to park (Car, Bus, motobike): ";
        std::cin >> type;

        if (type == "car")
        lot.parkVehicle(new Car(currentID++));
        else if (type == "bus")
        lot.parkVehicle( new Bus(currentID++));
        else if ( type == "motorbike")
        lot.parkVehicle( new Motorbike(currentID++));
        else
        std::cout << "Invalid type.\n";

    }

    int idToRemove;
    std::cout << "Enter ID of vehicle to unpark: ";
    std::cin >> idToRemove;

    lot.unparkVehicle(idToRemove);

    return 0;

}
