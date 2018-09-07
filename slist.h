#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this -> current = this->current->next;
        }
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
        int nodes;
              
    public:
        SList() {
            nodes = 0;
            head = nullptr;
        }

        bool find(T search, Node<T> **&pointer) {
            // TODO
        }
             
        bool insert(T data) {
            // TODO
        }
             
        bool remove(T item) {
            // TODO
        }  
             
        iterator begin() {
            return iterator(head);
            // TODO
        }
             
        iterator end() {
            auto* temp = head;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            return iterator(temp);
            // TODO
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif