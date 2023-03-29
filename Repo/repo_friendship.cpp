#include "repo_friendship.h"


RepoFriendship::RepoFriendship(std::string FileName): RepoFile(FileName){
    this->load();
}

void RepoFriendship::add_friendship(const FriendShip &f){
    if(!this->friendships.add_elem(f))
        throw Exception("ID or username in use");
}

bool RepoFriendship::friendship_exists(const FriendShip &f) const{
    return this->friendships.contains(f);
}

bool RepoFriendship::remove_friendship(const FriendShip &f){
    return this->friendships.remove_elem(f);
}

std::vector<FriendShip> RepoFriendship::get_all_friendship() const{
    std::vector<FriendShip> res;
    for(auto i = friendships.begin(); i != friendships.end(); i++){
        res.push_back(*i);
    }
    return res;
}

void RepoFriendship::save(){
    std::ofstream fout = this->open_write();
    for(auto i = friendships.begin(); i != friendships.end(); ++i){
        (*i).save_in_file(fout, SEPARATOR);
    }
    fout.close();
}

void RepoFriendship::load(){
    std::ifstream fin = this->open_read();
    if(!fin.is_open()) return;
    FriendShip u;
    while(!fin.eof()){
        u.get_from_file(fin, SEPARATOR);
        if(u.get_ID() == 0){
            fin.close();
            return;
        }
        this->friendships.add_elem(u);
    }
    fin.close();
}