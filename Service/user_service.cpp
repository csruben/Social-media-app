#include "user_service.h"


UserService::UserService(RepoUsers users) {
    this->users = users;
    users.load();
}

void UserService::add_user(int id, string user_name) {
    try {
        User user(id, user_name);

        this->users.add_user(user);
    } catch (std::exception &e) {
        throw e;
    }
}

std::vector<User> UserService::get_all_users() const {
    return users.get_all_users();
}

void UserService::save() {
    this->users.save();
}

bool UserService::delete_user(int id, string user_name) {
    try {
        User user(id, user_name);
        return this->users.remove_user(user);
    } catch(std::exception &e){
        throw e;
    }
}

void UserService::update_user(int id, string user_name, string new_user_name) {
    try {
        User user(id, user_name);
        User new_user(id, new_user_name);
        this->users.update_user(user, new_user);
    } catch(std::exception &e){
        throw e;
    }
}

bool UserService::user_exist(int id, string user_name) {
    User user(id, user_name);
    return this->users.user_exists(user);
}

string UserService::return_name(int id) {
    string user_n = "";
    for(User u: users.get_all_users())
        if(u.get_ID() == id)
            user_n = u.get_user_name();
    return user_n;
}