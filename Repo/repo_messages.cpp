#include "repo_messages.h"

RepoMessages::RepoMessages(std::string FileName): RepoFile(FileName){
    this->load();
}

bool RepoMessages::add_message(const Message &m){
    if(this->messages.key_exists(std::make_pair(m.get_id_receiver(), m.get_id_sender())))
        return this->messages.put(std::make_pair(m.get_id_receiver(), m.get_id_sender()), m);
    else
        return this->messages.put(std::make_pair(m.get_id_sender(), m.get_id_receiver()), m);
}

std::vector<Message> RepoMessages::get_all_users_messages(const long unsigned &u1, const long unsigned &u2) const{
    if(this->messages.key_exists(std::make_pair(u1, u2)))
        return this->messages.get_all_key_values(std::make_pair(u1, u2));
    else
        return this->messages.get_all_key_values(std::make_pair(u2, u1));
}

bool RepoMessages::remove_message(const Message &m){
    if(this->messages.key_exists(std::make_pair(m.get_id_receiver(), m.get_id_sender())))
        return this->messages.remove_value(std::make_pair(m.get_id_receiver(), m.get_id_sender()), m);
    else
        return this->messages.remove_value(std::make_pair(m.get_id_sender(), m.get_id_receiver()), m);
}

std::vector<Message> RepoMessages::remove_chat(const long unsigned &u1, const long unsigned &u2){
    if(this->messages.key_exists(std::make_pair(u1, u2)))
        return this->messages.remove_key(std::make_pair(u1, u2));
    else
        return this->messages.remove_key(std::make_pair(u2, u1));
}

void RepoMessages::save(){
    std::ofstream fout = this->open_write();
    std::vector<Message> msgs;
    for(auto i = messages.begin(); i != messages.end(); ++i){
        msgs.push_back(i.second());
    }
    for(int i = msgs.size() - 1; i >= 0; --i)
        msgs[i].save_in_file(fout, SEPARATOR);
    fout.close();
}

void RepoMessages::load(){
    std::ifstream fin = this->open_read();
    if(!fin.is_open()) return;
    Message m;
    while(!fin.eof()){
        m.get_from_file(fin, SEPARATOR);
        if(m.get_ID() == 0 || m.get_id_receiver() == 0
        || m.get_id_sender() == 0 ||m.get_text() == ""){
            fin.close();
            return;
        }
        if(this->messages.key_exists(std::make_pair(m.get_id_receiver(), m.get_id_sender())))
            this->messages.put(std::make_pair(m.get_id_receiver(), m.get_id_sender()), m);
        else
            this->messages.put(std::make_pair(m.get_id_sender(), m.get_id_receiver()), m);
    }
    fin.close();
}
