#pragma once
#include "../Repo/repo_users.h"
#include "../Entities/user.h"


class UserService{
private:
    RepoUsers users;
public:
    UserService() = default;
    explicit UserService(RepoUsers users);

    void add_user(int id, string user_name);
    bool delete_user(int id, string user_name);
    bool user_exist(int id, string user_name);
    void update_user(int id, string user_name, string new_user_name);
    string return_name(int id);

    void save();
    std::vector<User> get_all_users() const;
};