#pragma once

template<class T>
class Set{
private:
    class Node{
    public:
        Node *next;
        Node *prev;
        T value;
        Node():value(T()), next(nullptr), prev(nullptr){}
        Node(T value): value(value), next(nullptr), prev(nullptr){}
        Node(T value, Node *prev, Node *next): value(value), next(next), prev(prev){}
    };

    Node *first;
    int sz;

    Node *find(const T &elem){
        Node *tmp = this->first;
        while(tmp){
            if(tmp->value == elem)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }
public:

    Set(); // default constructor
    Set(const Set &s); // copy constructor

    Set<T> &operator=(const Set<T> &s);

    bool operator==(const Set<T> &s) const;

    bool add_elem(const T &elem);

    bool remove_elem(const T &elem);

    bool contains(const T &elem) const;

    bool is_empty() const;

    Set<T> operator+(const Set<T> &s) const; // reunion
    Set<T> operator*(const Set<T> &s) const; //intersection
    Set<T> operator-(const Set<T> &s) const; // difference


    int size(){
        return sz;
    }

    ~Set();

public:

    /*
     * clasa pt iterator
    */
    class iterator{
    private:
        Node *current;
    public:
        iterator(){
            current = nullptr;
        }

        void next(){
            this->current = this->current->next;
        }

        bool valid() const{
            return this->current != nullptr;
        }

        iterator &operator++(){
            this->next();
            return *this;
        }

        iterator operator++(int){
            iterator tmp(*this);
            this->operator++();
            return tmp;
        }

        bool operator==(const iterator &it) const{
            return this->current == it.current;
        }

        bool operator!=(const iterator &it) const{
            return this->current != it.current;
        }

        T operator*() const{
            return this->current->value;
        }

        friend class Set<T>;
    };

    /*
    First element in the set
    */
    iterator begin() const {
        iterator tmp;
        tmp.current = this->first;
        return tmp;
    }

    /*
    Element after the last element in the set
    */
    iterator end() const {
        iterator tmp;
        tmp.current = nullptr;
        return tmp;
    }
};

#include "set.cpp"