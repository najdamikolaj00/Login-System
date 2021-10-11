#include <iostream>
#include "systemoperator.cpp"
int request();

int main()
{
    System *user = new System();
    
    int response = System::request();
    if (response == 1)
        user->registration();
    else
        user->login();

    delete user;    

    return 0;
}
