#pragma once
#include <vector>
#include <iostream>

template <class Key, class Value>
class MultiMap{
private:
    /*
    Class to retain value added
    */
    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
    };


    template <class K, class V>
    class MapNode {
    public:
        K key;
        V value;
        MapNode<K, V> *next;
        MapNode(K key, V value) : key(key), value(value){ this->next= nullptr;}
        MapNode(K key, V value, MapNode<K, V> *next) : key(key), value(value), next(next){}
    };

    MapNode<Key, ListNode<Value>*> *first;
    int size; // number of values in map

    MapNode<Key, ListNode<Value> *> *GetKeyNode(Key key) const{
        MapNode<Key, ListNode<Value> *> *tmp = this->first;
        while(tmp && tmp->key != key){
            tmp = tmp->next;
        }
        return tmp;
    }

public:
    MultiMap(); // default constructor

    MultiMap(const MultiMap &m); //copy constructor

    std::vector<Value> get_all_key_values(Key key) const;

    std::vector<Value> get_last_key_values(Key key, int n) const;

    bool put(Key key, Value value);

    std::vector<Value> remove_key(Key key);

    bool remove_value(Key key, Value value);

    bool update_value(Key key, Value oldVal, Value newVal);

    bool key_exists(Key k) const;

    std::vector<Key> get_all_keys() const;

    friend std::ostream &operator<<(std::ostream &out, const MultiMap<Key, Value> &multimap){
        MapNode<Key, ListNode<Value>*> *tmp = multimap.first;
        while(tmp){
            out<<tmp->key<<std::endl;
            ListNode<Value> *ln_tmp = tmp->value;
            while(ln_tmp){
                out<<"  "<<ln_tmp->info<<std::endl;
                ln_tmp = ln_tmp->next;
            }
            tmp = tmp->next;
        }
        return out;
    }

    MultiMap &operator=(const MultiMap &m);


    ~MultiMap();
public:
    /*
     * Clasa pt iterator.
    */
    class iterator{
    private:
        MapNode<Key, ListNode<Value> *> *current;
        ListNode<Value> *currentln;
    public:
        iterator(){
            current = nullptr;
            currentln = nullptr;
        }
        iterator(const iterator &it){
            current = it.current;
            currentln = it.currentln;
        }

        void next(){
            this->current = this->current->next;
        }

        bool valid(){
            return this->current != nullptr;
        }
        
        iterator &operator++(){
            this->currentln = this->currentln->next;
            if(!currentln){
                this->next();
                if(this->current){
                    this->currentln = this->current->value;
                }
            }
            return *this;
        }

        iterator operator++(int){
            iterator tmp(*this);
            this->operator++();
            return tmp;
        }

        bool operator==(const iterator &it){
            return this->current == it.current && this->currentln == it.currentln;
        }

        bool operator!=(const iterator &it){
            return this->current != it.current || this->currentln != it.currentln;
        }

        std::pair<Key, Value> operator*(){
            return std::make_pair(this->current->key, this->currentln->info);
        }

        Key first(){
            if(current)
                return this->current->key;
            return {};
        }

        Value second(){
            if(currentln)
                return this->currentln->info;
            return {};
        }

        friend class MultiMap<Key, Value>;
    };

    iterator begin() const{
        iterator sbegin;
        sbegin.current = this->first;
        if(this->first)
            sbegin.currentln = this->first->value;
        return sbegin;
    }

    iterator end() const{
        iterator send;
        send.current = nullptr;
        send.currentln = nullptr;
        return send;
    }
};

#include "multimap.cpp"
