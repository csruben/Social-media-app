#pragma once
#include "../Repo/repo_messages.h"
#include "../Entities/message.h"
class MessageService {
private:
    RepoMessages repoMessages;
public:
    MessageService() = default;

    explicit MessageService(RepoMessages messages);

    bool add_message(int id, string text, int id_sender, int id_receiver);
    bool delete_message(int id, string text, int id_sender, int id_receiver);
    void remove_chat(int id_sender, int id_reveiver);
    std::vector<Message> get_messages_users(long id_user_1, long id_user_2);

    void save();
};