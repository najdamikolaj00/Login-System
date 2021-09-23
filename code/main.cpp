#include <iostream>
#include "systemoperator.cpp"
int request();

int main()
{
    int response = request();
    System user;

    if (response == 1)
        user.registration();
    else
        user.login();    

    return 0;
}
int request()
{
    //make it with this heritence or whatever
    std:: cout << "registration: 1" << std:: endl;
    std:: cout << "login: 2" << std:: endl;
    std:: cout << "choice: ";

    int choice;
    std:: cin >> choice;
    return choice;
}