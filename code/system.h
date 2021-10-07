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
        static int request()
                            {
                std:: cout << "registration: 1" << std:: endl;
                std:: cout << "login: 2" << std:: endl;
                std:: cout << "choice: ";

                int choice;
                std:: cin >> choice;
                return choice;
                            }
};
#endif


