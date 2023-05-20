#include <iostream>
#include <vector>
#include <string>

struct Bus {
    int number;
    std::string driverName;
    int routeNumber;
    bool isOnRoute;
};

void displayBuses(const std::vector<Bus>& buses, bool isInPark) {
    std::cout << "Buses " << (isInPark ? "in the park:" : "on the route:") << std::endl;
    for (const auto& bus : buses) {
        if (bus.isOnRoute == isInPark) {
            std::cout << "Number: " << bus.number << std::endl;
            std::cout << "Driver: " << bus.driverName << std::endl;
            std::cout << "Route: " << bus.routeNumber << std::endl;
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<Bus> busPark;
    int choice;

    do {
        std::cout << "1. Add bus to the park" << std::endl;
        std::cout << "2. Add bus to the route" << std::endl;
        std::cout << "3. Display buses in the park" << std::endl;
        std::cout << "4. Display buses on the route" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Bus bus;
            std::cout << "Enter bus number: ";
            std::cin >> bus.number;
            std::cout << "Enter driver's name: ";
            std::cin.ignore();
            std::getline(std::cin, bus.driverName);
            std::cout << "Enter route number: ";
            std::cin >> bus.routeNumber;
            bus.isOnRoute = false;
            busPark.push_back(bus);
            break;
        }
        case 2: {
            int busNumber;
            std::cout << "Enter bus number: ";
            std::cin >> busNumber;
            for (auto& bus : busPark) {
                if (bus.number == busNumber) {
                    bus.isOnRoute = true;
                    break;
                }
            }
            break;
        }
        case 3:
            displayBuses(busPark, true); // Display buses in the park
            break;
        case 4:
            displayBuses(busPark, false); // Display buses on the route
            break;
        case 5:
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 5);

    return 0;
}
