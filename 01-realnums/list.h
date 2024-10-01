#ifndef INC_240421_LIST_LIST_H
#define INC_240421_LIST_LIST_H

template<typename T>
struct list_node {
    T value;
    list_node<T> *prev = nullptr, *next = nullptr;
    list_node(T value) {
        this->value = value;
    }
};

template<typename T>
class list {
public:
    bool empty();
    void push_back(T value);
    list_node<T>* find(T needle);
    list_node<T>* find_last(T needle);
    list_node<T>* begin();
    list_node<T>* end();
    void insert(list_node<T> *after, T value);
    void insert_before(list_node<T> *before, T value);
    void remove(list_node<T> *node);
private:
    list_node<T> *head = nullptr, *tail = nullptr;
};

template<typename T>
list_node<T> *list<T>::end() {
    return tail;
}

template<typename T>
list_node<T> *list<T>::begin() {
    return head;
}

template<typename T>
bool list<T>::empty() {
    return head == nullptr;
}

template<typename T>
void list<T>::remove(list_node<T> *node) {
    if(node->next && node->prev) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    } else if(node == head && node->next) {
        head = node->next;
        head->prev = nullptr;
    } else if(node == tail && node->prev) {
        tail = node->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
}

template<typename T>
void list<T>::insert(list_node<T> *after, T value) {
    if(after == tail) {
        push_back(value);
        return;
    }
    list_node<T>* new_node = new list_node<T>(value);
    new_node->prev = after;
    if(after->next) {
        new_node->next = after->next;
        after->next->prev = new_node;
    }
    after->next = new_node;
}

template<typename T>
void list<T>::insert_before(list_node<T> *before, T value) {
    if(before != head) {
        insert(before->prev, value);
        return;
    }
    list_node<T>* new_node = new list_node<T>(value);
    if(before) {
        new_node->next = before;
        before->prev = new_node;
    }
    head = new_node;
}

template<typename T>
list_node<T> *list<T>::find_last(T needle) {
    list_node<T>* cur = tail;
    while(cur) {
        if(cur->value == needle) break;
        cur = cur->prev;
    }
    return cur;
}

template<typename T>
list_node<T> *list<T>::find(T needle) {
    list_node<T>* cur = head;
    while(cur) {
        if(cur->value == needle) break;
        cur = cur->next;
    }
    return cur;
}

template<typename T>
void list<T>::push_back(T value) {
    list_node<T>* val = new list_node<T>(value);
    if(!head && !tail) {
        head = val;
    } else {
        tail->next = val;
        val->prev  = tail;
    }
    tail = val;
}

#endif //INC_240421_LIST_LIST_H
