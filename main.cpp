#define _CRT_SECURE_NO_WARNINGS

#include "PrinterQueue.h"
#include "StatisticsQueue.h"
#include "Client.h"
#include <iostream>
#include <ctime>

int main() {
    PrinterQueue printerQueue;
    StatisticsQueue statisticsQueue;

   
    for (int i = 0; i < 5; ++i) {
        std::string clientName = "Client" + std::to_string(i);
        int priority = rand() % 10 + 1; 
        Client client(clientName.c_str(), priority);

        
        printerQueue.enqueue(client);

        
        time_t timestamp;
        time(&timestamp);
        statisticsQueue.enqueue(client.getName(), ctime(&timestamp));
    }

    
    statisticsQueue.printStatistics();

    
    while (!printerQueue.isEmpty()) {
        Client currentClient = printerQueue.dequeue();
        std::cout << "Printing document for client: " << currentClient.getName() << " with priority: "
            << currentClient.getPriority() << std::endl;
    }

    return 0;
}
