#include "repo_users.h"

RepoUsers::RepoUsers(std::string FileName): RepoFile(FileName){
    this->load();
}

void RepoUsers::add_user(const User &u){
    if(!this->users.add_elem(u))
        throw Exception("ID or username in use");
}

bool RepoUsers::user_exists(const User &u) const{
    return this->users.contains(u);
}

bool RepoUsers::remove_user(const User &u){
    return this->users.remove_elem(u);
}

std::vector<User> RepoUsers::get_all_users() const{
    std::vector<User> res;
    for(auto i = users.begin(); i != users.end(); i++){
        res.push_back(*i);
    }
    return res;
}

void RepoUsers::update_user(const User &OldUser, const User &NewUser){
    if(OldUser.get_ID() != NewUser.get_ID()) throw Exception("Cant update IDs");

    if(this->remove_user(OldUser)){
        this->add_user(NewUser);
    }else{
        throw Exception("No user to update");
    }
}

void RepoUsers::save(){
    std::ofstream fout = this->open_write();
    for(auto i = users.begin(); i != users.end(); ++i){
        (*i).save_in_file(fout, SEPARATOR);
    }
    fout.close();
}

void RepoUsers::load(){
    std::ifstream fin = this->open_read();
    if(!fin.is_open()) return;
    User u;
    while(!fin.eof()){
        u.get_from_file(fin, SEPARATOR);
        if(u.get_ID() == 0){
            fin.close();
            return;
        }
        this->users.add_elem(u);
    }
    fin.close();
}
