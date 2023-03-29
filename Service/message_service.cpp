#include "message_service.h"


MessageService::MessageService(RepoMessages messages) {
    this->repoMessages = messages;
    messages.load();
}

void MessageService::save() {
    this->repoMessages.save();
}

bool MessageService::add_message(int id, string text, int id_sender, int id_receiver) {
    Message message(id, text, id_sender, id_receiver);
    return this->repoMessages.add_message(message);
}

bool MessageService::delete_message(int id, string text, int id_sender, int id_receiver) {
    Message message(id, text, id_sender, id_receiver);
    return this->repoMessages.remove_message(message);
}

void MessageService::remove_chat(int id_sender, int id_reveiver) {
    this->repoMessages.remove_chat(id_sender, id_reveiver);
}

 std::vector<Message> MessageService::get_messages_users(long id_user_1, long id_user_2) {
     return this->repoMessages.get_all_users_messages(id_user_1, id_user_2);
}