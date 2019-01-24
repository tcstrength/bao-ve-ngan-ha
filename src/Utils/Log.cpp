#include "Log.h"

Log::Log()
{
    _outStream.open("log.txt");
}

Log::~Log()
{
    _outStream.close();
}

Log* Log::instance()
{
    static Log log;
    return &log;
}

std::stringstream& Log::stream()
{
    return _strStream;
}

void Log::print(std::string level)
{
    std::string str = "[ " + getStrTime() + " " + level + " ] - " + _strStream.str();

    std::cout << str << std::endl;
    _outStream << str << std::endl;

    _strStream.str("");
}

void Log::debug()
{
    print("DEBUG");
}

void Log::error()
{
    print("ERROR");
}

std::string Log::getStrTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%H:%M:%S",timeinfo);
    std::string str(buffer);
    return str;
}
