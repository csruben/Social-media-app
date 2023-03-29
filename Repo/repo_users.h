#pragma once
#include "repo_file.h"
#include "../Template/set.h"
#include "../Entities/user.h"
#include "../Exception/Exeption.h"
#include <vector>

class RepoUsers: public RepoFile{
private:
    Set<User> users;
public:
    RepoUsers(): RepoFile(){}
    RepoUsers(std::string FileName);

    void add_user(const User &u);
    bool user_exists(const User &u) const;
    bool remove_user(const User &u);
    std::vector<User> get_all_users() const;
    void update_user(const User &OldUser, const User &NewUser);

    void save();
    void load();

    ~RepoUsers(){}
};