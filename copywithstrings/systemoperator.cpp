#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "system.h"

const int MAX_LOGIN_ATTEMPTS = 3;

int System::request()
{
    std:: cout << "registration: 1" << std:: endl;
    std:: cout << "login: 2" << std:: endl;
    std:: cout << "choice: ";

    int choice;
    std:: cin >> choice;
    return choice;
}
System::System()
{
    nickname_len_ = 4;
    password_len_ = 4;
    pt_nickname_ = new char[1];
    pt_password_ = new char[1];
    pt_nickname_[0] = '\0';
    pt_password_[0] = '\0';
}
System::System(const char *nickname, const char *password)
{
    nickname_len_ = std::strlen(nickname);
    password_len_ = std::strlen(password);
    pt_nickname_ = new char[nickname_len_ + 1];
    pt_password_ = new char[password_len_ + 1];
    std::strcpy(pt_nickname_, nickname);
    std::strcpy(pt_password_, password);
}
System::~System()
{
    delete [] pt_nickname_;
    delete [] pt_password_;
}
void System::registration()
{
    std:: ofstream outFile;
    outFile.open("credentials.csv", std::ios_base::app);
    if (!outFile.is_open())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        std:: cout << "new nickname: ";
        std:: cin >> pt_nickname_;

        std::string temp_nickname;
        std::string temp_password;

        std:: ifstream checkFile;
        checkFile.open("credentials.csv");

        while(getline(checkFile, temp_nickname, ',') && getline(checkFile, temp_password, '\n'))
        {   
            if (temp_nickname.compare(pt_nickname_) == 0)
            {
                std::cout << "nickname already exists." << std::endl;
                registration();
            }
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
void System::login()
{
    for (int i = 0; i < MAX_LOGIN_ATTEMPTS; ++i)
    {
        std:: cout << "nickname: ";
        std:: cin >> pt_nickname_;
        std:: cout << "password: ";
        std:: cin >> pt_password_;
        
        std:: ifstream outFile;
        outFile.open("credentials.csv");

        if(!outFile.is_open())
        {
            std::cout << "ERROR: File Open" << std::endl;
            exit;
        }
        std::string temp_nickname;
        std::string temp_password;
        while(getline(outFile, temp_nickname, ',') && getline(outFile, temp_password, '\n'))
        {

            if (temp_nickname.compare(pt_nickname_) == 0)
            {
                if (temp_password.compare(pt_password_) == 0)
                {
                    std::cout <<"Successfull login." << std::endl;
                    //przejście do panelu sterowania
                    exit(0);
                }
                else
                {
                    std::cout << "Wrong password or login." << std::endl;
                    exit(0);
                }
            }
        }
    }
}
// friend///// int request()
// {
//     std:: cout << "registration: 1" << std:: endl;
//     std:: cout << "login: 2" << std:: endl;
//     std:: cout << "choice: ";

//     int choice;
//     std:: cin >> choice;
//     return choice;
// }
