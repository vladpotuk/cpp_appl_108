#ifndef CLIENT_H
#define CLIENT_H

class Client {
public:
    static const int MAX_NAME_LENGTH = 50;

    Client(const char* name, int priority);

    Client(); 

    void setName(const char* name);

    void setPriority(int priority);

    const char* getName() const;

    int getPriority() const;

private:
    char name[MAX_NAME_LENGTH];
    int priority;
};

#endif 
