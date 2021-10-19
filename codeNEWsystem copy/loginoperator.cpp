#include <iostream>
#include <fstream>
#include <cstring>
#include "login.h"

const int MAX_LOGIN_ATTEMPTS  = 3;

Login::Login()
{
    nickname_len_ = 4;
    password_len_ = 4;
    pt_nickname_ = new char[1];
    pt_password_ = new char[1];
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
void Login::login()
{
    auto login_attempt = [&] ()
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
                password[strlen(password)-1] = 0;
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
                    count += 1;
                }
                else if (count == 20)
                {
                    std:: cout << std::endl << "Too many characters" << std::endl;
                }

            }
        }

        int length = strlen(password);
        if(length != 0)
        {
            password[length - 1] = '\0';
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
                }
            }
            nicknames_.pop();
            passwords_.pop();
        }
    };
    for (int i = 0; i < MAX_LOGIN_ATTEMPTS; ++i)
        {
            login_attempt();
            if  (i == (MAX_LOGIN_ATTEMPTS - 1))
                {
                    std::cout << std::endl << "Too many login attempts." << std::endl;
                    exit(0);
                } 
        }
}
