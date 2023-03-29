#pragma once
#include "repo_file.h"
#include "../Template//multimap.h"
#include "../Entities/message.h"
#include "../Entities/user.h"
#include "../Exception/Exeption.h"


class RepoMessages: public RepoFile{
private:
public:
    MultiMap<std::pair<long unsigned, long unsigned>, Message> messages;
    RepoMessages(): RepoFile(){}
    RepoMessages(std::string FileName);

    bool add_message(const Message &m);
    bool remove_message(const Message &m);


    std::vector<Message> get_all_users_messages(const long unsigned &u1, const long unsigned &u2) const;

    std::vector<Message> remove_chat(const long unsigned &u1, const long unsigned &u2);

    void save();
    void load();

    ~RepoMessages(){}
};
