#include <iostream>
#include "systemoperator.cpp"
int request();

int main()
{
    System user;
    int response = request();

    if (response == 1)
        user.registration();
    else
        user.login();    

    return 0;
}
