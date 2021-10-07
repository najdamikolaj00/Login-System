#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <string>
#include <fstream>
#include <iostream>

class System
{
    private:
        std::string nickname_;
        std::string password_;
    public:
        System();
        explicit System(std::string nickname, std::string password);
        ~System();
        void registration();
        void login();
        // friend int request();
        static int request();
};
#endif


