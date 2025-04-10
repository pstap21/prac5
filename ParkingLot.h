#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "Vehicle.h"
#include <vector>


class ParkingLot {
    private:
    Vehicle** vehicles;
    int capacity;
    int count;

    public:
    ParkingLot (int maxCapacity);
    ~ParkingLot();
     int getCount() const;
     void parkVehicle(Vehicle* v);
     void unparkVehicle(int id);
    int countOverstayingVehicles(int maxParkingDuration) const;

};

#endif

