#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <thread>
#include <iomanip>
#include "Vehicle.h"
#include "Motorbike.h"
#include "Car.h"
#include "Bus.h"


int main() {
    int numCars, numBuses, numBikes;
    int currentID = 1;

    std::cout << "Enter number of cars to park: ";
    std::cin >> numCars;
    std::cout << "Enter number of buses to park: ";
    std::cin >> numBuses;
    std::cout << "Enter number of motorbikes to park: ";
    std::cin >> numBikes;

    std::vector<Vehicle*> vehicles;

    for (int i = 0; i < numCars; ++i)
        vehicles.push_back(new Car(currentID++));

    for (int i = 0; i < numBuses; ++i)
        vehicles.push_back(new Bus(currentID++));

    for (int i = 0; i < numBikes; ++i)
        vehicles.push_back(new Motorbike(currentID++));

    std::cout << "\nWaiting 3 seconds to simulate parking time...\n\n";
    sleep(3); // Sleep for 3 seconds

    for (Vehicle* v : vehicles) {
        std::cout << "Vehicle ID " << v->getID()
                  << " parked for " << v->getParkingDuration()
                  << " seconds.\n";
    }

    for (Vehicle* v : vehicles)
        delete v;

    return 0;
}
