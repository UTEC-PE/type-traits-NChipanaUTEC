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
            return *this;
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

        bool find(T search, Node<T> **&pointer) { // Podría reducirse un poco
            for(int i = 0;i < nodes; i++){
                if(cmp(search,(*pointer)-> data)){break;}
                pointer = &((*pointer) -> next);
            }
            if((*pointer) == nullptr){return false;}
            else if((*pointer)->data == search){return true;}
            else{return false;}
            // TODO
        }

        bool insert(T data) {
            auto** pointer = &head;
            if(find(data,pointer)){return false;}
            else{
                auto* temp = new Node<T>(data);
                if(nodes == 0){ // No es necesario tener el caso base, estás repitiendo código
                    *pointer = temp;
                    temp -> next = nullptr;
                    nodes ++;
                    return true;
                }
                else{
                    auto* aux = *pointer;
                    *pointer = temp;
                    temp -> next = aux;
                    nodes ++;
                    return true;
                }
            }
            // TODO
        }

        bool remove(T item) {
            auto** pointer = &head;
            if(!find(item,pointer)){
                return false;
            }
            else{
                auto* temp=(*pointer)->next;
                if(nodes == 1){ 
                    temp = *pointer;
                    *pointer = nullptr;
                    delete temp;
                    return true;
                }
                else{
                    auto* aux = *pointer;
                    *pointer = temp;
                    delete aux;
                    return true;
                }
            }
            // TODO
        }

        iterator begin() {
            return iterator(head);
            // TODO
        }

        iterator end() {
            auto* temp = head;
            while(temp != nullptr){
                temp = temp -> next;
            }
            return iterator(temp); // Bastaría con iterator(nullptr)
            // TODO
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif