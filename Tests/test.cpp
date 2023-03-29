#include "test.h"
#include "../Entities/user.h"
#include "../Entities/message.h"
#include "../Entities/friendship.h"
#include "../Template/set.h"
#include "../Template/multimap.h"
#include "../Repo/repo_file.h"
#include "../Repo/repo_users.h"
#include "../Service/user_service.h"
#include "../Service/message_service.h"
#include "../Repo/repo_messages.h"
#include "../Repo/repo_friendship.h"
#include "../Service/friendship_service.h"
#include "../Entities/friendship.h"
#include <cassert>

void myTest(){
    set_test();
    multimap_test();
    service_test();
}

void set_test(){
    Set<int> sets;

    sets.add_elem(1);
    assert(sets.size() == 1);

    sets.add_elem(2);
    assert(sets.size() == 2);

    sets.add_elem(3);
    assert(sets.size() == 3);

    sets.remove_elem(1);
    assert(sets.size() == 2);

    assert(sets.is_empty() == false);

    assert(sets.contains(2) == true);
    assert(sets.contains(1) == false);
}

void multimap_test(){
    MultiMap<int, int> mm, mm2;
    assert(mm.put(1, 5));
    assert(mm.put(1, 7));
    assert(!mm.put(1, 5));
    assert(mm.put(2, 10));
    assert(mm.put(3, 5));

    assert(mm.get_all_key_values(1).size() == 2);

    mm2 = mm;

    assert(mm.remove_key(3).size() == 1);
    assert(!mm.key_exists(3));
    assert(mm.remove_key(3).size() == 0);

    assert(mm2.get_all_key_values(1).size() == 2);
    assert(mm2.key_exists(3));
    assert(mm2.remove_key(3).size() == 1);
    assert(mm2.remove_key(3).size() == 0);
}


void service_test(){
    RepoUsers repo("user_test.txt");

    UserService userService(repo);

    userService.add_user(1, "Ioan");
    userService.add_user(2, "Ion");
    userService.delete_user(1, "Ioan");
    //userService.save();

    //assert(userService.get_all_users().size() == 2);

    RepoMessages repoMessages("message_test.txt");

    MessageService messageService(repoMessages);

    messageService.add_message(1, "teste", 1, 2);

    messageService.add_message(2, "teste2", 1, 3);

    //messageService.delete_message(2, "teste2", 1, 3);
    messageService.remove_chat(1, 2);

    //messageService.save();

    RepoFriendship friendships("friendship_test.txt");
    FriendShipService friendShipService(friendships);
    friendShipService.add_friendship(1, 1, 2, true);


    vector<FriendShip> vect = friendShipService.get_all_friendships();
    assert(vect.size() == 1);
    //friendShipService.save();
}