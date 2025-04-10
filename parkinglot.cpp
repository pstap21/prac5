#include <iostream>
#include "parkinglot.h"

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
        std::cout << "The lot is full.\n";
        delete v;
        return;


    }
    vehicles[count++] = v;
    std::cout << "Vehicle ID" << v->getID() << " parked.\n";

}

void ParkingLot::unparkVehicle( int id) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (vehicles[i] -> getID() == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Vehicle not in the lot.\n";
        return;
    }

    delete vehicles[index];
    for (int i = 0; i < count; i++) {
        vehicles[i] = vehicles[i +1];

    }
    --count;
    std::cout << "Vehicle ID" << id << " removed from the lot.\n";

}