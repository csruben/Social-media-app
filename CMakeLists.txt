cmake_minimum_required(VERSION 3.20)
project(SDA_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDA_Project main.cpp Entities/User.h  Entities/message.h Entities/Entity.h Entities/friendship.h
        Exception/Exeption.h Template/set.h Tests/test.h Tests/test.cpp Repo/repo_file.h Repo/repo_users.cpp Repo/repo_users.h
        Template/multimap.h Repo/repo_messages.cpp Repo/repo_messages.h Service/user_service.cpp Service/user_service.h
        Service/message_service.cpp Service/message_service.h UI/UI.h UI/UI.cpp Repo/repo_friendship.cpp Repo/repo_friendship.h
        Service/friendship_service.cpp Service/friendship_service.h)
