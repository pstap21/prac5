#include "Car.h"
#include <ctime>

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int rawDuration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return static_cast<int>(rawDuration * 0.90); }
    
