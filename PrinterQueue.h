#ifndef PRINTERQUEUE_H
#define PRINTERQUEUE_H

#include "Client.h"

class PrinterQueue {
public:
    PrinterQueue();
    ~PrinterQueue();

    void enqueue(const Client& client);

    Client dequeue();

    bool isEmpty() const;

private:
    Client* queue;
    int maxSize;
    int currentSize;

    void sortQueue();
};

#endif 
