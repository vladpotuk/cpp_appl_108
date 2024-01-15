#include "StatisticsQueue.h"
#include <iostream>

void StatisticsQueue::enqueue(const std::string& clientName, const std::string& timestamp) {
    if (size < MAX_SIZE) {
        statistics[size].clientName = clientName;
        statistics[size].timestamp = timestamp;
        size++;
    }
}

void StatisticsQueue::printStatistics() const {
    std::cout << "Printing Statistics:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Client: " << statistics[i].clientName << ", Time: " << statistics[i].timestamp << std::endl;
    }
    std::cout << std::endl;
}
