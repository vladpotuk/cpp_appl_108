#include "PrinterQueue.h"
#include "Client.h"

PrinterQueue::PrinterQueue() : maxSize(10), currentSize(0) {
    queue = new Client[maxSize];
}

PrinterQueue::~PrinterQueue() {
    delete[] queue;
}

void PrinterQueue::enqueue(const Client& client) {
    if (currentSize < maxSize) {
        queue[currentSize++] = client;
        sortQueue();
    }
}

Client PrinterQueue::dequeue() {
    if (currentSize > 0) {
        Client front = queue[0];
        for (int i = 1; i < currentSize; ++i) {
            queue[i - 1] = queue[i];
        }
        currentSize--;
        return front;
    }
    return Client("", 0);  
}

bool PrinterQueue::isEmpty() const {
    return currentSize == 0;
}

void PrinterQueue::sortQueue() {
    for (int i = 0; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize - i - 1; ++j) {
            if (queue[j].getPriority() < queue[j + 1].getPriority()) {
                Client temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}
