#pragma once
#include "repo_file.h"
#include "../Template/set.h"
#include "../Entities/friendship.h"
#include "../Exception/Exeption.h"
#include <vector>

class RepoFriendship: public RepoFile{
private:
    Set<FriendShip> friendships;
public:
    RepoFriendship(): RepoFile(){}

    RepoFriendship(std::string FileName);

    void add_friendship(const FriendShip &f);

    bool friendship_exists(const FriendShip &f) const;

    bool remove_friendship(const FriendShip &u);

    std::vector<FriendShip> get_all_friendship() const;

    void save();
    void load();

    ~RepoFriendship(){}
};