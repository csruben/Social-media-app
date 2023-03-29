#pragma once

#include <exception>

class Exception: public std::exception{
private:
    char *msg;
public:
    Exception(char *msg): exception(msg), msg(msg){}
    char *what(){
        return msg;
    }
};