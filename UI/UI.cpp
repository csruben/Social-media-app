#include "UI.h"


UI::UI(UserService &userService, MessageService &messageService, FriendShipService &friendShipService) {
    this->userService = userService;
    this->messageService = messageService;
    this->friendShipService = friendShipService;
}

void UI::run_console() {
    while(true){
        show_menu();
        int opt;
        cin >> opt;
        if(opt == 0)
            break;
        else if(opt == 1)
            add_user();
        else if(opt == 2)
            delete_user();
        else if(opt == 3)
            update_user();
        else if(opt == 4)
            show_all_users();
        else if(opt == 5)
            exist_user();
        else if(opt == 6)
            add_message();
        else if(opt == 7)
            delete_message();
        else if(opt == 8)
            show_all_messages();
        else if(opt == 9)
            add_friendship();
        else if(opt == 10)
            delete_friendship();
        else if(opt == 11)
            exist_friendship();
        else if(opt == 12)
            save();
        else
            cout << "Necunoscut!! Reincercati" << endl;
    }
}

void UI::show_menu() {
    cout << "0. Iesire" << endl;
    cout << "1. Adauga user" << endl;
    cout << "2. Stergere user" << endl;
    cout << "3. Update user" << endl;
    cout << "4. Afisare user" << endl;
    cout << "5. Cautare user" << endl << endl;

    cout << "6. Adauga mesaj" << endl;
    cout << "7. Stergere mesaj" << endl;
    cout << "8. Afisare mesaje users" << endl << endl;

    cout << "9. Adauga prietenie" << endl;
    cout << "10. Stergere prietenie" << endl;
    cout << "11. Cautare prietenie" << endl << endl;

    cout << "12. Save" << endl;
}

void UI::add_user() {
    try {
        int id_user;
        string user_name;

        cout << endl << "ID: ";
        cin >> id_user;

        cout << endl << "Nume: ";
        cin >> user_name;

        cout << endl;
        userService.add_user(id_user, user_name);
    }catch(std::exception &e){
        std::cout<<e.what();
    }
}

void UI::delete_user() {
    int id_user;
    string user_name;

    cout << endl << "ID: ";
    cin >> id_user;

    cout << endl << "Nume: ";
    cin >> user_name;

    cout << endl;
    userService.delete_user(id_user, user_name);
}

void UI::update_user() {
    try{
        int id_user;
        string user_name, user_new_name;

        cout << endl << "ID: ";
        cin >> id_user;

        cout << endl << "Nume: ";
        cin >> user_name;

        cout << endl << "Noul nume: ";
        cin >> user_new_name;
        userService.update_user(id_user, user_name, user_new_name);
    }catch(std::exception &e){
        std::cout<<e.what();
    }
}

void UI::show_all_users() {
    for(User p: userService.get_all_users())
        cout << p.get_ID() << " " << p.get_user_name() << endl;
}

void UI::exist_user() {
    int id;
    string name;

    cout << endl << "ID: ";
    cin >> id;

    cout << endl << "Nume: ";
    cin >> name;

    if(userService.user_exist(id, name))
        cout << "User ul exista!" << endl;
    else
        cout << "Nu exista acest user!" << endl;
}

void UI::add_message() {
    int id, id_1, id_2;
    string mess;

    cout << "id: ";
    cin >> id;

    cout << endl << "ID sender: ";
    cin >> id_1;

    cout << endl << "ID receiver: ";
    cin >> id_2;

    cout << endl << "message: ";
    cin >> mess;

    messageService.add_message(id, mess, id_1, id_2);
}

void UI::delete_message() {
    long id_user_1, id_user_2;
    string user_1, user_2;

    cout << endl << "id user 1: ";
    cin >> id_user_1;

    cout << endl << "id user 2: ";
    cin >> id_user_2;

    messageService.remove_chat(id_user_1, id_user_2);
}

void UI::show_all_messages() {
    int u1, u2;
    cout << endl << "id user1: ";
    cin >> u1;

    cout << endl << "id user2: ";
    cin >> u2;

    for(Message m: messageService.get_messages_users(u1, u2))
        cout << m.get_ID() << " " << userService.return_name(m.get_id_sender()) << " " <<
        userService.return_name(m.get_id_receiver()) << " " << m.get_text() << endl;
}

void UI::add_friendship() {
    try{
        int id, id_user_1, id_user_2;

        cout << endl << "id: ";
        cin >> id;

        cout << endl << "id user 1: ";
        cin >> id_user_1;

        cout << endl << "id user 2: ";
        cin >> id_user_2;

        friendShipService.add_friendship(id, id_user_1, id_user_2, true);
    }catch(std::exception &e){
        std::cout<<e.what();
    }
}

void UI::delete_friendship() {
    int id, id_user_1, id_user_2;

    cout << endl << "ID: ";
    cin >> id;

    cout << endl << "Id user 1: ";
    cin >> id_user_1;

    cout << endl << "Id user 2: ";
    cin >> id_user_2;

    friendShipService.delete_friendship(id, id_user_1, id_user_2, false);
}

void UI::exist_friendship() {
    int id, id_user_1, id_user_2;

    cout << endl << "ID: ";
    cin >> id;

    cout << endl << "Id user 1: ";
    cin >> id_user_1;

    cout << endl << "Id user 2: ";
    cin >> id_user_2;

    if(friendShipService.friendship_exist(id, id_user_1, id_user_2, true))
        cout << "Prietenia exista!" << endl;
    else cout << "Utilizatorii nu sunt prieteni! " << endl;
}

void UI::show_all_friendships() {
    for(FriendShip f: friendShipService.get_all_friendships())
        cout << f.get_ID() << " " << userService.return_name(f.get_id_user1()) << " " <<
        userService.return_name(f.get_id_user2()) << endl;
}

void UI::save() {
    userService.save();
    friendShipService.save();
    messageService.save();
}