#include <iostream>
#include "ParkingLot.h"

ParkingLot::ParkingLot(int maxCapacity){
    capacity = maxCapacity;
    count = 0;
    vehicles = new Vehicle*[capacity];

}

ParkingLot::~ParkingLot(){
    for (int i = 0; i < count; i++)
    delete vehicles[i];
    delete[] vehicles;

}

int ParkingLot::getCount() const {
    return count;

}

void ParkingLot::parkVehicle(Vehicle* v) {
    if (count >= capacity) {
        std::cout << "The lot is full\n";
        delete v;
        return;


    }
    vehicles[count++] = v;
    std::cout << "Vehicle ID" << v->getID() << " parked.\n";

}

void ParkingLot::unparkVehicle(int id) {
    for (int i = 0; i < count; ++i) {
        if (vehicles[i]->getID() == id) {
            std::cout << "Vehicle ID" << id << " removed from the lot." << std::endl;

            // Delete the vehicle
            delete vehicles[i];

            // Shift remaining vehicles down
            for (int j = i; j < count - 1; ++j) {
                vehicles[j] = vehicles[j + 1];
            }

            --count;
            return;
        }
    }

    std::cout << "Attempt to remove a vehicle not in the lot: " << std::endl;
    std::cout << "Vehicle not in the lot" << std::endl;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int count = 0;
    for (Vehicle* v : vehicles) {
        if (v->getParkingDuration() > maxParkingDuration)
            ++count;
    }
    return count;
}
