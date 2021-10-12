#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "credentialsqueue.h"

Queue::Queue()
{
    
}
Queue::~Queue()
{

}
void Queue::store()
{
    std:: ifstream outFile;
    outFile.open("credentials.csv");

    if(!outFile.is_open())
    {
        std::cout << "ERROR: File Open" << std::endl;
        exit(0);
    }

    std::string temp_nickname;
    std::string temp_password;

    while(getline(outFile, temp_nickname, ',') && getline(outFile, temp_password, '\n'))
    {
        nicknames_.push(temp_nickname);
        passwords_.push(temp_password);
    }
}
void Queue::printing()
{
    while (!nicknames_.empty()) {
        std::cout << ' ' << nicknames_.front();
        nicknames_.pop();
    }
}