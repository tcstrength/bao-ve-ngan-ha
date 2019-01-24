#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <bitset>

#define USE_DEBUG

#ifdef USE_DEBUG
#define LOG_DEBUG(str) \
do { \
    Log::instance()->stream() << str; \
    Log::instance()->debug(); \
} while(0)

#define LOG_ERROR(str) \
do { \
    Log::instance()->stream() << str; \
    Log::instance()->error(); \
} while(0)

#else
#define LOG_DEBUG(str)
#define LOG_ERROR(str)
#endif

class Log {
public:
    static Log* instance();

    void debug();

    void error();

    std::stringstream& stream();
private:
    Log();

    ~Log();

    void print(std::string level);

    std::string getStrTime();

    std::stringstream _strStream;
    std::ofstream _outStream;
};

#endif // LOG_H
