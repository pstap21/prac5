#include <iostream>
#include <thread>
#include <chrono>
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    ParkingLot lot(10);
    int idCounter = 1;

    // Park 5 Cars
    for (int i = 0; i < 5; ++i)
        lot.parkVehicle(new Car(idCounter++));

    // Park 3 Buses
    for (int i = 0; i < 3; ++i)
        lot.parkVehicle(new Bus(idCounter++));

    // Park 2 Motorbikes
    for (int i = 0; i < 2; ++i)
        lot.parkVehicle(new Motorbike(idCounter++));

    // Try to add 1 more vehicle to test full lot handling
    if (!lot.parkVehicle(new Car(idCounter))) {
        std::cout << "Parking lot is full. Cannot add vehicle with ID " << idCounter << ".\n";
    }

    // Wait to simulate time passing
    std::cout << "Waiting 16 seconds to simulate parking duration...\n";
    std::this_thread::sleep_for(std::chrono::seconds(16));

    // Count overstaying vehicles
    int overstayed = lot.countOverstayingVehicles(15);
    std::cout << overstayed << " vehicles have overstayed more than 15 seconds.\n";

    return 0;
}
