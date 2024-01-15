#ifndef STATISTICSQUEUE_H
#define STATISTICSQUEUE_H

#include <string>

class StatisticsQueue {
public:
    void enqueue(const std::string& clientName, const std::string& timestamp);

    void printStatistics() const;

private:
    struct StatisticEntry {
        std::string clientName;
        std::string timestamp;
    };

    static const int MAX_SIZE = 100; 
    StatisticEntry statistics[MAX_SIZE];
    int size = 0;
};

#endif 

