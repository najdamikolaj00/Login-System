#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "registration.h"

int Registration::request()
{
    std:: cout << "registration: 1" << std:: endl;
    std:: cout << "login: 2" << std:: endl;
    std:: cout << "choice: ";

    int choice;
    std:: cin >> choice;
    return choice;
}
Registration::Registration()
{
    nickname_len_ = 4;
    password_len_ = 4;
    pt_nickname_ = new char[1];
    pt_password_ = new char[1];
    pt_nickname_[0] = '\0';
    pt_password_[0] = '\0';
}
Registration::Registration(const char *nickname, const char *password)
{
    nickname_len_ = std::strlen(nickname);
    password_len_ = std::strlen(password);
    pt_nickname_ = new char[nickname_len_ + 1];
    pt_password_ = new char[password_len_ + 1];
    std::strcpy(pt_nickname_, nickname);
    std::strcpy(pt_password_, password);
}
Registration::~Registration()
{
    delete [] pt_nickname_;
    delete [] pt_password_;
}
void Registration::registration()
{
    std:: ofstream outFile;
    outFile.open("credentials.csv", std::ios_base::app);
    if (!outFile.is_open())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        store();
        std:: cout << "new nickname: ";
        std:: cin >> pt_nickname_;

        std::string temp_nickname;
        std::string temp_password;

        std:: ifstream checkFile;
        checkFile.open("credentials.csv");
        
        while (!nicknames_.empty()) 
        {
            if (nicknames_.front().compare(pt_nickname_) == 0)
            {
                std::cout << "nickname already exists." << std::endl;
                registration();
            }
            nicknames_.pop();
            passwords_.pop();
        }

        checkFile.close();
        std:: cout << "new password: ";
        std:: cin >> pt_password_;

        outFile << pt_nickname_ << "," << pt_password_ << std::endl;
        outFile.close();
        std:: cout << "Succesfully registration!" << std::endl;
        login();
    }
}
