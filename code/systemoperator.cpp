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
    //1.check if file with this nickname exist
    //2.if not create this file (nickname.txt) and save password there
    //3.if file with this nickname exist say that this nickname is not free to use
    //4.than do it unless user create free nickname
    //5.than go to 2 point
    //6.after registration go to login()
    std:: cout << "new nickname: ";
    std:: cin >> nickname_;
    std:: cout << "new password: ";
    std:: cin >> password_;
    

}
void System::login()
{
    std:: cout << "new nickname: ";
    std:: cin >> nickname_;
    std:: cout << "new password: ";
    std:: cin >> password_;
}
