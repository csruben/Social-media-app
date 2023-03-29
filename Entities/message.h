#pragma once
#include <iostream>
#include <string>
#include "Entity.h"
using namespace std;


class Message: public Entity{
private:
    unsigned int id_sender;
    unsigned int id_receiver;
    string text;

public:
    Message(): Entity(){
        text = "";
        id_sender = 0;
        id_receiver = 0;
    };

    Message(const unsigned long &ID, const std::string &Text, const unsigned int &id_Sender,
            const unsigned int &id_Receiver): Entity(ID),
                                            text(Text), id_sender(id_Sender), id_receiver(id_Receiver){}

    Message(const Message &m): Entity(m.ID), text(m.text), id_sender(m.id_sender), id_receiver(m.id_receiver){}

    unsigned int get_id_sender() const{
        return this->id_sender;
    };

    unsigned int get_id_receiver() const{
        return this->id_receiver;
    };

    string get_text(){
        return this->text;
    };

    void set_text(string txt){
        this->text = txt;
    };

    bool operator != (Message &message){
        return message.ID != ID || message.id_sender != id_sender || message.id_receiver != id_receiver || message.text != text;
    };

    bool operator == (Message &message){
        return message.ID == ID && message.id_sender == id_sender && message.id_receiver == id_receiver && message.text == text;
    };

    void save_in_file(std::ofstream &fout, std::string separator) const{
        if(!fout.is_open() || fout.bad()) return;
        fout<<ID<<separator<<id_sender<<separator<<id_receiver<<separator<<text<<std::endl;
    }

    void get_from_file(std::ifstream &fin, std::string separator){
        if(!fin.is_open() || fin.bad()) return;
        std::string line;
        getline(fin, line);
        size_t pos = 0;
        std::string token;
        ID = 0;
        int n = 0;
        id_sender = 0;
        id_receiver = 0;
        text = "";
        while ((pos = line.find(separator)) != std::string::npos && n < 3) {
            token = line.substr(0, pos);
            switch(n){
                case 0: ID = stoi(token); break;
                case 1: id_sender = stoi(token); break;
                case 2: id_receiver = stoi(token); break;
            }
            ++n;
            line.erase(0, pos + separator.length());
        }
        text = line;
    }

};

