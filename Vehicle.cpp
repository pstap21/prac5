#include "Vehicle.h"
#include "Motorbike.h"
#include "Car.h"
#include "Bus.h"
#include <ctime>

Vehicle::Vehicle(int id) : ID(id), timeOfEntry(std::time(nullptr)) {}

int Vehicle::getID() const {
    return ID;
}

Vehicle::~Vehicle() {}

