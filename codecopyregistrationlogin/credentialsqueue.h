#ifndef CREDENTIALSQUEUE_H_
#define CREDENTIALSQUEUE_H_
#include <queue>
#include <string>

class Queue
{
    private:
        std::queue <std::string> nicknames_;
        std::queue <std::string> passwords_;
    public:
        Queue();
        ~Queue();
        void store();
        void printing();
};
#endif