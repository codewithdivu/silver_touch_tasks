#include <iostream>
using namespace std;

class Logger
{
private:
    Logger() {}
    static Logger *instance;

public:
    static Logger *getInstance()
    {
        if (!instance)
        {
            instance - new Logger();
        }
        return instance;
    }

    void dispaly()
    {
        cout << "hello logger class" << endl;
    }
};

Logger *Logger::instance = nullptr;

int main()
{
    Logger *loggerInstance = Logger::getInstance();
    loggerInstance->dispaly();
    return 0;
}