#pragma once
#include <string>
#include <fstream>
#include <ostream>

class Entity{
protected:
    unsigned long ID;
public:
    Entity(): ID(0){}
    Entity(const unsigned long &ID): ID(ID){}
    Entity(const Entity &e):ID(e.ID){}

    void set_ID(unsigned long ID){
        this->ID = ID;
    }

    unsigned long get_ID() const{
        return this->ID;
    }

    virtual void save_in_file(std::ofstream &fout, std::string separator) const{
        if(!fout.is_open() || fout.bad()) return;
        fout<<ID<<std::endl;
    }

    virtual void get_from_file(std::ifstream &fin, std::string separator){
        if(!fin.is_open() || fin.bad()) return;
        std::string line;
        getline(fin, line);
        ID = 0;
        ID = stoi(line);
    }

};
