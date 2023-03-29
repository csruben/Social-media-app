#pragma once
#include "../Service/message_service.h"
#include "../Service/user_service.h"
#include "../Service/friendship_service.h"
#include <iostream>
#include "../Exception/Exeption.h"
using namespace std;

class UI{
private:
    FriendShipService friendShipService;
    MessageService messageService;
    UserService userService;

    void show_menu();

    void add_user();
    void delete_user();
    void update_user();
    void show_all_users();
    void exist_user();

    void add_message();
    void delete_message();
    void show_all_messages();

    void add_friendship();
    void delete_friendship();
    void exist_friendship();
    void show_all_friendships();

    void save();

public:
    UI() = default;
    explicit UI(UserService& userService, MessageService& messageService, FriendShipService& friendShipService);

    void run_console();
    ~UI() = default;
};