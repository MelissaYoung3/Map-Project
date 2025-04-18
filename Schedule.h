#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <map>
#include <fstream>
#include <sstream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    void initSchedule(std::ifstream& inFile);
    void addEntry(const ScheduleItem& item);
    void print() const;
    void printHeader() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructorLastName(const std::string& lastName) const;
};

#endif
