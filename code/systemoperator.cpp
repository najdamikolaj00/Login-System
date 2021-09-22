#include <iostream>
#include <fstream>
#include <string>
#include "system.h"

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
        std:: cout << "new password: ";
        std:: cin >> password_;

        std::string temp_nickname;
        std::string temp_password;
        std:: ifstream checkFile;
        checkFile.open("credentials.csv");
        while(getline(checkFile, temp_nickname, ',') && getline(checkFile, temp_password, '\n'))
        {   
            if (temp_nickname.compare(nickname_) == 0)
            {
                std::cout << "nickname already exists." << std::endl;
                exit(1);
            }
        }
        checkFile.close();

        outFile << nickname_ << "," << password_ << std:: endl;
        outFile.close();
    }
}
void System::login()
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
            break;
            }
            else
            {
            std::cout << "Wrong password." << std::endl;
            exit;
            }
        }
    }
    
}
