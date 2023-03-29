#include "friendship_service.h"

FriendShipService::FriendShipService(RepoFriendship friendship) {
    this->friendships = friendship;
    friendship.load();
}

void FriendShipService::add_friendship(long id, int id_user_1, int id_user_2, bool are_friends) {
    FriendShip f(id, id_user_1, id_user_2, are_friends);

    this->friendships.add_friendship(f);
}

std::vector<FriendShip> FriendShipService::get_all_friendships() const {
    return friendships.get_all_friendship();
}

void FriendShipService::save() {
    this->friendships.save();
}

bool FriendShipService::delete_friendship(long id, int id_user_1, int id_user_2, bool are_friends) {
    FriendShip f(id, id_user_1, id_user_2, are_friends);
    return this->friendships.remove_friendship(f);
}

bool FriendShipService::friendship_exist(long id, int id_user_1, int id_user_2, bool are_friends) {
    FriendShip f(id, id_user_1, id_user_2, are_friends);
    return this->friendships.friendship_exists(f);
}