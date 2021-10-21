#include "registration.h"

int MAX_REGISTRATION_ATTEMPTS  = 3;

int Registration::request()
{
    std:: cout << "registration: 1" << std:: endl;
    std:: cout << "login: 2" << std:: endl;
    std:: cout << "choice: ";

    int choice;
    std:: cin >> choice;
    return choice;
}
Registration::Registration()
{
    nickname_len_ = 20;
    password_len_ = 20;
    pt_nickname_ = new char[20];
    pt_password_ = new char[20];
    pt_nickname_[0] = '\0';
    pt_password_[0] = '\0';
}
Registration::Registration(const char *nickname, const char *password)
{
    nickname_len_ = std::strlen(nickname);
    password_len_ = std::strlen(password);
    pt_nickname_ = new char[nickname_len_ + 1];
    pt_password_ = new char[password_len_ + 1];
    std::strcpy(pt_nickname_, nickname);
    std::strcpy(pt_password_, password);
}
Registration::~Registration()
{
    delete [] pt_nickname_;
    delete [] pt_password_;
}
void Registration::registration_attempt()
{
    if (MAX_REGISTRATION_ATTEMPTS == 0)
    {
        std::cout << "Registration attempt failed" << std::endl;
        exit(1);
    }
    MAX_REGISTRATION_ATTEMPTS -= 1;
    registration();
}
void Registration::registration()
{
    std:: ofstream outFile;
    outFile.open("credentials.csv", std::ios_base::app);
    if (!outFile.is_open())
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        store();
        std:: cout << "new nickname: ";
        std:: cin >> pt_nickname_;

        std:: ifstream checkFile;
        checkFile.open("credentials.csv");
        
        
        
        while (!nicknames_.empty()) 
        {
            if (nicknames_.front().compare(pt_nickname_) == 0)
            {
                std::cout << "nickname already exists." << std::endl;
                registration();
            }
            nicknames_.pop();
            passwords_.pop();
        }
        
        checkFile.close();

        std:: cout << "new password: ";
        char *password = new char[20];
        int key, count{0};

        while(key!=13)
        {
            key = getch();

            if (key == 8)
            {
                if(count != 0)
                {
                    password[count - 1] = '\0';
                    count -= 1;
                    key = getch();
                    password[count] = key;
                    count += 1;
                    std::cout << "*";
                    continue;
                }
                continue;
            }
            else if (key == 13)
            {
                break;
            }
            else
            {	
                if (count < 20)
                {
                    std::cout << "*";
                    password[count] = key;
                    password[count + 1] = '\0';
                    count += 1;
                }
                else if (count == 20)
                {
                    std:: cout << "Too many characters" << std::endl;
                }

            }
        }
        if (std::strlen(password) < 8)
        {
            std:: cout << std::endl << "Password too short. Try to include at least 8 characters" << std::endl;
            registration_attempt();
        }
        std::strcpy(pt_password_, password);
        delete [] password;
        
        outFile << pt_nickname_ << "," << pt_password_ << std::endl;
        outFile.close();
        std:: cout << std::endl << "Succesfully registration!" << std::endl;
        login_attempt();
        
    }
}
