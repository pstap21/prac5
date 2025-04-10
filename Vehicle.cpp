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

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(difftime(now, timeOfEntry));
    return static_cast<int>(duration * 0.9); // 10% reduction
}

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(difftime(now, timeOfEntry));
    return static_cast<int>(duration * 0.75); // 25% reduction
}

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    std::time_t now = std::time(nullptr);
    int duration = static_cast<int>(difftime(now, timeOfEntry));
    return static_cast<int>(duration * 0.85); // 15% reduction
}
