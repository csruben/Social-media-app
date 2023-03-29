#pragma once
#include "../Repo/repo_friendship.h"
#include "../Entities/friendship.h"


class FriendShipService {
private:
    RepoFriendship friendships;
public:
    FriendShipService() = default;

    explicit FriendShipService(RepoFriendship friendship);

    void add_friendship(long id, int id_user_1, int id_user_2, bool are_friends);

    bool delete_friendship(long id, int id_user_1, int id_user_2, bool are_friends);

    bool friendship_exist(long id, int id_user_1, int id_user_2, bool are_friends);

    void save();

    std::vector<FriendShip> get_all_friendships() const;
};