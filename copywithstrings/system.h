#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <string>
#include <fstream>
#include <iostream>

class System
{
    private:
        char *pt_nickname_;
        char *pt_password_;
        int nickname_len_;
        int password_len_;
        static const int CINLIM = 80;
    public:
        System();
        explicit System(const char *nickname, const char *password);
        System(const System &);
        ~System();
        void registration();
        void login();
        // friend int request();
        static int request();
};
#endif


