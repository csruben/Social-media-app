#pragma once

#include <ostream>
#include "Entity.h"
using namespace std;

class FriendShip: public Entity{
private:
    int id_user1;
    int id_user2;
    bool are_friends;
public:
    FriendShip():Entity(){
        id_user1 = 0;
        id_user2 = 0;
        are_friends = false;
    }

    FriendShip(const unsigned long &ID, int id_User1, int id_User2, bool are_Friends):
    Entity(ID), id_user1(id_User1), id_user2(id_User2), are_friends(are_Friends){}

    FriendShip(const FriendShip &f): Entity(f.ID), id_user1(f.id_user1), id_user2(f.id_user2), are_friends(f.are_friends){}

    int get_id_user1() const{
        return this->id_user1;
    };

    int get_id_user2() const{
        return this->id_user2;
    }

    bool get_are_friends(){
        return this->are_friends;
    }

    void set_id_user_1(int id1){
        this->id_user1 = id1;
    }

    void set_id_user_2(int id2){
        this->id_user2 = id2;
    }

    void set_are_friends(bool are_f){
        this->are_friends = are_f;
    }

    void save_in_file(std::ofstream &fout, std::string separator) const{
        if(!fout.is_open() || fout.bad()) return;
        fout<<ID<<separator<<id_user1<<separator<<id_user2<<separator<<are_friends<<std::endl;
    }

    void get_from_file(std::ifstream &fin, std::string separator){
        if(!fin.is_open() || fin.bad()) return;
        std::string line;
        getline(fin, line);
        size_t pos = 0;
        std::string token;
        ID = 0;
        int n = 0;
        id_user1 = 0;
        id_user2 = 0;
        are_friends = false;
        while ((pos = line.find(separator)) != std::string::npos && n < 3) {
            token = line.substr(0, pos);
            switch(n){
                case 0: ID = stoi(token); break;
                case 1: id_user1 = stoi(token); break;
                case 2: id_user2 = stoi(token); break;
            }
            ++n;
            line.erase(0, pos + separator.length());
        }
        if(line == "true" || line == "1")
            are_friends = true;
    }

    bool operator==(const FriendShip &f){
        return ID == f.ID && id_user1 == f.id_user1 && id_user2 == f.id_user2 && are_friends == f.are_friends;
    }


};

