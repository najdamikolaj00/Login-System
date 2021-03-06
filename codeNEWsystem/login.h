#ifndef LOGIN_H_
#define LOGIN_H_
#include <string>
#include <fstream>
#include <iostream>
#include "credentialsqueue.h"

class Login: public virtual Queue
{
    private:
        char *pt_nickname_;
        char *pt_password_;
        int nickname_len_;
        int password_len_;
    public:
        Login();
        explicit Login(const char *nickname, const char *password);
        Login(const Login &);
        ~Login();
        void login();
};
#endif