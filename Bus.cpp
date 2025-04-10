#include "Bus.h"
#include <ctime>

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int rawDuration = static_cast<int>(std::time(nullptr) - timeOfEntry);
    return static_cast<int>(rawDuration * 0.75); 
}
