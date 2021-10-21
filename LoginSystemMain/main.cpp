#include "registrationoperator.cpp"
#include "loginoperator.cpp"
#include "credentialsqueueoperator.cpp"

int main()
{
    Registration *user = new Registration();
    
    int response = Registration::request();
    if (response == 1)
        user->registration_attempt();
    else
        user->login_attempt();

    delete user;    
    
    return 0;
}
