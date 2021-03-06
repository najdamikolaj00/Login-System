#include <iostream>
#include <fstream>
#include <string>
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
    std::string nickname = "nonickname";
    std::string password = "nopassword";
}
System::System(std::string nickname, std::string password)
{
    nickname_ = nickname;
    password_ = password;
}
System::~System()
{
    std:: cout << "goodbye " << nickname_ << std:: endl;
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
        std:: cin >> nickname_;

        std::string temp_nickname;
        std::string temp_password;

        std:: ifstream checkFile;
        checkFile.open("credentials.csv");

        while(getline(checkFile, temp_nickname, ',') && getline(checkFile, temp_password, '\n'))
        {   
            if (temp_nickname.compare(nickname_) == 0)
            {
                std::cout << "nickname already exists." << std::endl;
                registration();
            }
        }
        checkFile.close();
        std:: cout << "new password: ";
        std:: cin >> password_;

        outFile << nickname_ << "," << password_ << std::endl;
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
        std:: cin >> nickname_;
        std:: cout << "password: ";
        std:: cin >> password_;
        
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
            if (temp_nickname.compare(nickname_) == 0)
            {
                if (temp_password.compare(password_) == 0)
                {
                    std::cout <<"Successfull login." << std::endl;
                    //przej??cie do panelu sterowania
                    exit(0);
                }
                else
                {
                    std::cout << "Wrong password or login." << std::endl;
                    continue;
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
