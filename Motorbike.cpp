#include "Motorbike.h"
#include <ctime>

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int rawDuration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return static_cast<int>(rawDuration * 0.85);
}
