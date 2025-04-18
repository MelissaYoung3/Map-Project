#include <iostream>
#include <fstream>
#include "Schedule.h"

int main() {
    Schedule schedule;
    std::ifstream file("schedule.csv");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return 1;
    }

    schedule.initSchedule(file);
    file.close();

    int choice;
    std::string input1, input2;

    do {
        std::cout << "\nCourse Schedule Menu:\n";
        std::cout << "1. Search by Subject\n";
        std::cout << "2. Search by Subject and Catalog\n";
        std::cout << "3. Search by Instructor Last Name\n";
        std::cout << "4. Display All Courses\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter Subject: ";
                std::getline(std::cin, input1);
                schedule.findBySubject(input1);
                break;
            case 2:
                std::cout << "Enter Subject: ";
                std::getline(std::cin, input1);
                std::cout << "Enter Catalog: ";
                std::getline(std::cin, input2);
                schedule.findBySubjectCatalog(input1, input2);
                break;
            case 3:
                std::cout << "Enter Instructor Last Name: ";
                std::getline(std::cin, input1);
                schedule.findByInstructorLastName(input1);
                break;
            case 4:
                schedule.print();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
