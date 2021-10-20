#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include "login.h"

int MAX_LOGIN_ATTEMPTS  = 3;

Login::Login()
{
    nickname_len_ = 20;
    password_len_ = 20;
    pt_nickname_ = new char[20];
    pt_password_ = new char[20];
    pt_nickname_[0] = '\0';
    pt_password_[0] = '\0';
}
Login::Login(const char *nickname, const char *password)
{
    nickname_len_ = std::strlen(nickname);
    password_len_ = std::strlen(password);
    pt_nickname_ = new char[nickname_len_ + 1];
    pt_password_ = new char[password_len_ + 1];
    std::strcpy(pt_nickname_, nickname);
    std::strcpy(pt_password_, password);
}
Login::~Login()
{
    delete [] pt_nickname_;
    delete [] pt_password_;
}
void Login::login_attempt()
{
    MAX_LOGIN_ATTEMPTS -= 1;
    if (MAX_LOGIN_ATTEMPTS == 0)
    {
        std::cout << "Login attempt failed" << std::endl;
        exit(1);
    }
    login();
}
void Login::login()
{
    store();
    std:: cout << "nickname: ";
    std:: cin >> pt_nickname_;
    std:: cout << "password: ";
    
    char *password = new char[20];
    int key, count{0};

    while(key!=13)
    {
        key = getch();

        if (key == 8)
        {
            if(count != 0)
            {
                password[count - 1] = '\0';
                count -= 1;
                key = getch();
                password[count] = key;
                count += 1;
                std::cout << "*";
                continue;
            }
            continue;
        }
        else if (key == 13)
        {
            break;
        }
        else
        {	
            if (count < 20)
            {
                std::cout << "*";
                password[count] = key;
                password[count + 1] = '\0';
                count += 1;
            }
            else if (count == 20)
            {
                std:: cout << "Too many characters" << std::endl;
            }

        }
    }
    
    std::strcpy(pt_password_, password);
    delete [] password;
    
    while (!nicknames_.empty()) 
    {
        if (nicknames_.front().compare(pt_nickname_) == 0)
        {
            if (passwords_.front().compare(pt_password_) == 0)
            {
                std::cout << std::endl <<"Successfull login." << std::endl;
                //przejście do panelu sterowania, na razie exit(0)
                exit(0);
            }
            else
            {
                std::cout << std::endl << "Wrong password or login." << std::endl;
                login_attempt();
            }
        }
        nicknames_.pop();
        passwords_.pop();
    }
    
}
