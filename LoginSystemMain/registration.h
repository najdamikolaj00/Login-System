#ifndef REGISTRATION_H_
#define REGISTRATION_H_
#include "login.h"

class Registration: public Login
{
    private:
        char *pt_nickname_;
        char *pt_password_;
        int nickname_len_;
        int password_len_;
    public:
        Registration();
        explicit Registration(const char *nickname, const char *password);
        Registration(const Registration &);
        ~Registration();
        void registration();
        static int request();
        void registration_attempt();
};
#endif


