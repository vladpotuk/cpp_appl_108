#include "Client.h"

Client::Client(const char* name, int priority) {
    setName(name);
    setPriority(priority);
}

Client::Client() : name{}, priority(0) {}

void Client::setName(const char* name) {
    int i = 0;
    while (name[i] != '\0' && i < MAX_NAME_LENGTH) {
        this->name[i] = name[i];
        i++;
    }
    this->name[i] = '\0';
}

void Client::setPriority(int priority) {
    this->priority = priority;
}

const char* Client::getName() const {
    return name;
}

int Client::getPriority() const {
    return priority;
}

