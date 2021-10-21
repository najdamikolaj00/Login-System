#ifndef CREDENTIALSQUEUE_H_
#define CREDENTIALSQUEUE_H_
#include <queue>
#include <string>

class Queue
{
    private:
        
    public:
        std::queue <std::string> nicknames_;
        std::queue <std::string> passwords_;
        Queue();
        ~Queue();
        void store();
        void printing();
};
#endif