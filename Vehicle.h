#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <thread>
#include <iomanip>
#include <unistd.h>

#include <ctime>

class Vehicle {
protected:
    int ID;
    std::time_t timeOfEntry;

public:
    Vehicle(int id);
    int getID() const;
    virtual int getParkingDuration() const = 0;
    virtual ~ Vehicle();
};

class Car : public Vehicle {
public:
    Car(int id);
    int getParkingDuration() const override;
};

class Bus : public Vehicle {
public:
    Bus(int id);
    int getParkingDuration() const override;
};

class Motorbike : public Vehicle {
public:
    Motorbike(int id);
    int getParkingDuration() const override;
};

#endif

