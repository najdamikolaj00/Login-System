#include <iostream>
#include "registrationoperator.cpp"
#include "loginoperator.cpp"
#include "credentialsqueueoperator.cpp"

int main()
{
    Queue test;
    test.store();
    test.printing();
    // Registration *user = new Registration();
    
    // int response = Registration::request();
    // if (response == 1)
    //     user->registration();
    // else
    //     user->login();

    // delete user;    
    
    return 0;
}
