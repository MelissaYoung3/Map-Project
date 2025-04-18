#include "Schedule.h"
#include <algorithm>
#include <iomanip>

void Schedule::initSchedule(std::ifstream& inFile) {
    std::string line;
    getline(inFile, line); // Skip header

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string field;
        ScheduleItem item;

        getline(ss, item.subject, ',');
        getline(ss, item.catalog, ',');
        getline(ss, item.section, ',');
        getline(ss, item.component, ',');
        getline(ss, item.session, ',');

        getline(ss, field, ','); // MinUnits - ignored
        getline(ss, field, ','); // Units
        item.units = std::stoi(field);

        getline(ss, field, ','); // TotEnrl
        item.totalEnrolled = std::stoi(field);

        getline(ss, field, ','); // CapEnrl
        item.capacityEnrolled = std::stoi(field);

        getline(ss, field, ','); // AcadOrg - ignored
        getline(ss, item.instructor, ',');

        addEntry(item);
    }
}

void Schedule::addEntry(const ScheduleItem& item) {
    scheduleMap[item.getKey()] = item;
}

void Schedule::printHeader() const {
    std::cout << std::left
              << std::setw(10) << "Subject"
              << std::setw(10) << "Catalog"
              << std::setw(10) << "Section"
              << std::setw(12) << "Component"
              << std::setw(10) << "Session"
              << std::setw(6)  << "Units"
              << std::setw(8)  << "TotEnrl"
              << std::setw(8)  << "CapEnrl"
              << std::setw(25) << "Instructor"
              << "\n";
}

void Schedule::print() const {
    printHeader();
    for (const auto& pair : scheduleMap) {
        pair.second.print();
    }
}

void Schedule::findBySubject(const std::string& subject) const {
    printHeader();
    for (const auto& pair : scheduleMap) {
        if (pair.second.subject == subject) {
            pair.second.print();
        }
    }
}

void Schedule::findBySubjectCatalog(const std::string& subject, const std::string& catalog) const {
    printHeader();
    for (const auto& pair : scheduleMap) {
        if (pair.second.subject == subject && pair.second.catalog == catalog) {
            pair.second.print();
        }
    }
}

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void Schedule::findByInstructorLastName(const std::string& lastName) const {
    std::string search = toLower(lastName);
    printHeader();
    for (const auto& pair : scheduleMap) {
        std::string instructorLast;
        size_t pos = pair.second.instructor.find(',');
        if (pos != std::string::npos) {
            instructorLast = pair.second.instructor.substr(0, pos);
        } else {
            instructorLast = pair.second.instructor;
        }

        if (toLower(instructorLast).find(search) != std::string::npos) {
            pair.second.print();
        }
    }
}
