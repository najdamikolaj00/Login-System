//First step: Program will ask if you want to register or login 
//Second step: registration() --> data will be stored in .txt file (temp)
//Third step: login() --> check if nickname and password is correct and give the response
//Fourth step: 
//First step: 
//First step: 
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