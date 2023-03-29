#pragma once
#include <string>
#include <iostream>
#include "Entity.h"
using namespace std;

class User: public Entity{
private:
    string user_name;
public:
    User():Entity(), user_name(""){}

    User(const unsigned long &ID, const std::string &userName): Entity(ID), user_name(userName){}

    User(const User &u): Entity(u.ID), user_name(u.user_name){}

    void set_user_name(const std::string &user_Name){
        this->user_name = user_Name;
    };

    string get_user_name(){
        return this->user_name;
    };

    bool operator==(const User &u){
        return ID == u.ID && user_name == u.user_name;
    };

    void save_in_file(std::ofstream &fout, std::string separator) const{
        if(!fout.is_open() || fout.bad()) return;
        fout<<ID<<separator<<user_name<<std::endl;
    }

    void get_from_file(std::ifstream &fin, const std::string separator){
        if(!fin.is_open() || fin.bad()) return;
        std::string line;
        getline(fin, line);
        if(line == ""){
            return;
        }
        size_t pos = 0;
        std::string token;
        int n = 0;
        ID = 0;
        pos = line.find(separator);
        token = line.substr(0, pos);
        ID = stoi(token);
        line.erase(0, pos + separator.length());
        user_name = line;
    }

};

