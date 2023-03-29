#include "set.h"
#include <iostream>

template<class T>
Set<T>::Set(){
    this->first = nullptr;
    this->sz = 0;
}


template<class T>
Set<T>::Set(const Set<T> &s){
    this->first = nullptr;
    this->sz = 0;
    Node *tmp = s.first;
    while(tmp){
        this->add_elem(tmp->value);
        tmp = tmp->next;
    }

}

template<class T>
Set<T>& Set<T>::operator=(const Set<T> &s){
    if(&s == this){
        return *this;
    }

    while(this->first){
        Node *tmp = this->first;
        this->first = this->first->next;
        delete tmp;
    }

    for(auto t = s.begin(); t != s.end(); ++t){
        this->add_elem(*t);
    }

    return *this;
}


template<class T>
bool Set<T>::contains(const T &elem) const{
    Node *tmp = this->first;
    while(tmp){
        if(tmp->value == elem)
            return true;
        tmp = tmp->next;
    }
    return false;
}

template<class T>
bool Set<T>::add_elem(const T &elem){
    if(this->contains(elem))
        return false;

    Node *tmp = this->first;
    if(tmp){
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new Node(elem, tmp, nullptr);
        sz++;
        return true;
    }
    this->first = new Node(elem, nullptr, nullptr);
    sz++;
    return true;
}

template<class T>
bool Set<T>::remove_elem(const T &elem){
    Node *tmp = this->find(elem);
    if(tmp){
        if(tmp->prev){
            tmp->prev->next = tmp->next;
        }else{
            this->first = tmp->next;
        }
        if(tmp->next){
            tmp->next->prev = tmp->prev;
        }
        delete tmp;
        sz--;
        return true;
    }
    return false;
}


template<class T>
bool Set<T>::is_empty() const{
    return this->first == nullptr;
}

template<class T>
Set<T>::~Set(){
    while(this->first){
        this->remove_elem(this->first->value);
    }
}

template<class T>
bool Set<T>::operator==(const Set<T> &s) const{
    for(auto t = s.begin(); t != s.end(); t++){
        if(!contains(*t)) return false;
    }
    return true;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T> &s) const{
    Set<T> res;
    for(auto t = begin(); t != end(); t++)
        res.add_elem(*t);
    for(auto t = s.begin(); t != s.end(); t++)
        res.add_elem(*t);
    return res;
} // reunion

template<class T>
Set<T> Set<T>::operator*(const Set<T> &s) const{
    Set<T> res;
    for(auto t = begin(); t != end(); t++){
        if(s.contains(*t)){
            res.add_elem(*t);
        }
    }
    return res;
} //intersection

template<class T>
Set<T> Set<T>::operator-(const Set<T> &s) const{
    Set<T> res;
    for(auto t = begin(); t != end(); t++){
        if(!s.contains(*t)){
            res.add_elem(*t);
        }
    }
    return res;
} // difference