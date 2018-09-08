#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this->current = this->current->next;
            return *this;
        }
        DListIterator<T> operator--(){
            this->current = this->current->prev;
            return *this;
        }
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
              
    public:
        DList() {
            nodes = 0;
            head = tail = nullptr;
        };

        void push_front(T data) {
            auto* temp = new Node<T>(data);
            if(nodes == 0){
                head = tail = temp;
            }
            else{
                head -> prev = temp;
                temp -> next = head;
                head = temp;
            }
            nodes ++;
            //TODO
        }
        void push_back(T data) {
            auto *temp = new Node<T>(data);
            if(nodes == 0){
                head = tail = temp;
            }
            else{
                temp = tail -> next;
                temp -> prev = tail;
                tail = temp;
            }
            nodes ++;
            // TODO
        }
             
        void pop_front() {
            auto* temp = head;
            if(nodes == 0){
                std::cout << "Lista Vacía";
            }
            else if(nodes == 1){
                head = tail = nullptr;
            }
            else{
                head -> next -> prev = nullptr;
                head = head -> next;
            }
            nodes --;
            // TODO
        }
             
        void pop_back() {
            auto* temp = tail;
            if(nodes == 0){
                std::cout << "Lista Vacía";
            }
            else if(nodes == 1){
                head = tail = nullptr;
            }
            else{
                tail -> prev -> next = nullptr;
                tail = tail -> prev;
            }
            nodes --;
            // TODO
        }
             
        iterator begin() {
            return iterator(head);
        }
             
        iterator end() {
            return iterator(tail);
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif