#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <iostream>
#include <iomanip>

struct ScheduleItem {
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totalEnrolled;
    int capacityEnrolled;
    std::string instructor;

    std::string getKey() const {
        return subject + "_" + catalog + "_" + section;
    }

    void print() const {
        std::cout << std::left
                  << std::setw(10) << subject
                  << std::setw(10) << catalog
                  << std::setw(10) << section
                  << std::setw(12) << component
                  << std::setw(10) << session
                  << std::setw(6)  << units
                  << std::setw(8)  << totalEnrolled
                  << std::setw(8)  << capacityEnrolled
                  << std::setw(25) << instructor
                  << "\n";
    }

    bool operator==(const ScheduleItem& other) const {
        return getKey() == other.getKey();
    }

    bool operator!=(const ScheduleItem& other) const {
        return !(*this == other);
    }

    bool operator>=(const ScheduleItem& other) const {
        return getKey() >= other.getKey();
    }
};

#endif
