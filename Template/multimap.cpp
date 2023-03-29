#include "multimap.h"


template <class Key, class Value>
MultiMap<Key, Value>::MultiMap(){
    first = nullptr; size = 0;
}


template <class Key, class Value>
MultiMap<Key, Value>::MultiMap(const MultiMap<Key, Value> &m){
    first = nullptr; size = 0;
    MapNode<Key, ListNode<Value> *> *tmp = m.first;

    while(tmp){
        std::vector<Value> v = m.get_all_key_values(tmp->key);
        for(long i = (long)v.size() - 1; i >= 0; i--){
            put(tmp->key, v[i]);
        }
        tmp = tmp->next;
    }
}


template <class Key, class Value>
std::vector<Value> MultiMap<Key, Value>::get_all_key_values(Key key) const{
    std::vector<Value> res;
    MapNode<Key, ListNode<Value> *> *m_tmp = this->GetKeyNode(key);
    if(m_tmp == nullptr)
        return res;
    ListNode<Value> *ln_tmp = m_tmp->value;
    while(ln_tmp){
        res.push_back(ln_tmp->info);
        ln_tmp = ln_tmp->next;
    }
    return res;
}


template <class Key, class Value>
std::vector<Value> MultiMap<Key, Value>::get_last_key_values(Key key, int n) const{
    std::vector<Value> res;
    if( n <= 0){
        return res;
    }

    MapNode<Key, ListNode<Value> *> *m_tmp = this->GetKeyNode(key);
    if(m_tmp == nullptr)
        return res;
    ListNode<Value> *ln_tmp = m_tmp->value;
    while(ln_tmp && res.size() < n){
        res.push_back(ln_tmp->info);
        ln_tmp = ln_tmp->next;
    }
    return res;
}

template<class Key, class Value>
std::vector<Key> MultiMap<Key, Value>::get_all_keys() const{
    std::vector<Key> res;
    MapNode<Key, ListNode<Value> *> *m_tmp = this->first;
    while(m_tmp){
        res.push_back(m_tmp->key);
        m_tmp = m_tmp->next;
    }
    return res;
}


template<class Key, class Value>
MultiMap<Key, Value> &MultiMap<Key, Value>::operator=(const MultiMap<Key, Value> &m){
    if(&m == this){
        return *this;
    }

    while(this->first){
        remove_key(this->first->key);
    }

    first = nullptr; size = 0;
    MapNode<Key, ListNode<Value> *> *tmp = m.first;

    while(tmp){
        std::vector<Value> v = m.get_all_key_values(tmp->key);
        for(long i = (long)v.size() - 1; i >= 0; i--){
            put(tmp->key, v[i]);
        }
        tmp = tmp->next;
    }


    return *this;
}


template <class Key, class Value>
bool MultiMap<Key, Value>::put(Key key, Value value){
    MapNode<Key, ListNode<Value>*> *tmp;
    if(tmp = this->GetKeyNode(key)){
        ListNode<Value> *ck_ln_tmp = tmp->value;
        while(ck_ln_tmp){
            if(ck_ln_tmp->info == value){
                return false;
            }
            ck_ln_tmp = ck_ln_tmp->next;
        }
        ListNode<Value> *ln_tmp = new ListNode<Value>(value, tmp->value);
        tmp->value = ln_tmp;
        this->size++;
        return true;
    }
    if(this->size == 0){
        this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
    }else{
        this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value), this->first);
    }
    
    this->size++;
    return true;
}


template <class Key, class Value>
std::vector<Value> MultiMap<Key, Value>::remove_key(Key key){
    std::vector<Value> res;
    MapNode<Key, ListNode<Value> *> *m_tmp = this->GetKeyNode(key);
    if(m_tmp == nullptr)
        return res;
    while(m_tmp->value){
        res.push_back(m_tmp->value->info);
        ListNode<Value> *l = m_tmp->value;
        m_tmp->value = m_tmp->value->next;
        delete l;
    }
    if(m_tmp == this->first){
        this->first = m_tmp->next;
    }else{
        MapNode<Key, ListNode<Value> *> *tmp2 = this->first;
        while(tmp2->next != m_tmp){
            tmp2 = tmp2->next;
        }
        tmp2->next = m_tmp->next;
    }

    delete m_tmp;
    return res;
}


template <class Key, class Value>
bool MultiMap<Key, Value>::key_exists(Key k) const{
    return GetKeyNode(k) != nullptr;
}


template <class Key, class Value>
bool MultiMap<Key, Value>::remove_value(Key key, Value value){
    MapNode<Key, ListNode<Value> *> *mn_tmp = GetKeyNode(key);
    if(mn_tmp){
        ListNode<Value> *ln_tmp = mn_tmp->value, *ln_tmp2 = mn_tmp->value;
        while(ln_tmp && ln_tmp->info != value){
            ln_tmp = ln_tmp->next;
        }
        if(!ln_tmp) return false;
        while(ln_tmp2->next != ln_tmp){
            ln_tmp2 = ln_tmp2->next;
        }
        ln_tmp2->next = ln_tmp->next;
        delete ln_tmp;
        return true;
    }
    return false;
}


template <class Key, class Value>
bool MultiMap<Key, Value>::update_value(Key key, Value oldVal, Value newVal){
    MapNode<Key, ListNode<Value> *> mn_tmp = GetKeyNode(key);
    if(mn_tmp){
        ListNode<Value> *ln_tmp = mn_tmp->value, *ln_tmp2;
        while(ln_tmp && ln_tmp->info != oldVal){
            ln_tmp = ln_tmp->next;
        }
        if(!ln_tmp) return false;

        ln_tmp->info = newVal;
        return true;
    }
    return false;
}

template <class Key, class Value>
MultiMap<Key, Value>::~MultiMap(){
    while(this->first){
        remove_key(this->first->key);
    }
}