#include <iostream>
#include "Entities/user.h"
#include "Entities/message.h"
#include "Entities/friendship.h"
#include <cassert>
#include "Template/set.h"
#include "Tests/test.h"
#include "UI/UI.h"

int main() {
    myTest();
    cout << "all tests are ok! : )) " << endl;

    RepoFriendship repoFriendship("../Data/repo_friendship.txt");
    RepoUsers repoUsers("../Data/repo_users.txt");
    RepoMessages repoMessages("../Data/repo_messages.txt");

    FriendShipService friendShipService(repoFriendship);
    UserService userService(repoUsers);
    MessageService messageService(repoMessages);

    UI ui(userService, messageService, friendShipService);
    ui.run_console();
}
