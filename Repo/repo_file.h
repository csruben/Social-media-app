#pragma once
#include <string>
#include <fstream>
#include "../Exception/Exeption.h"

const char SEPARATOR[] = " "; 

class RepoFile{
private:
    std::string fileName;
public:
    RepoFile(): fileName(""){}
    RepoFile(std::string FileName): fileName(FileName) {}

    void change_file(std::string filename){
        this->fileName = filename;
    }

    virtual void save() = 0;
    virtual void load() = 0;

    std::ofstream open_write(){
        return std::ofstream(fileName);
    }

    std::ifstream open_read(){
        return std::ifstream(fileName);
    }

    ~RepoFile(){}
};