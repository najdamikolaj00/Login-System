#include <iostream>
#include "registrationoperator.cpp"
#include "loginoperator.cpp"

int main()
{
    Registration *user = new Registration();
    
    int response = Registration::request();
    if (response == 1)
        user->registration();
    else
        user->login();

    delete user;    

    return 0;
}
