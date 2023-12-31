//
//  LinkedList.h
//
//  This file defines a Linked List class.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include "Collection.h"
#include <cassert>

using namespace std;

namespace csi281 {
    template
    <typename T>
    class LinkedList : public Collection<T> {
        class Node; // forward declaration
    public:
        // Erase all the nodes
        ~LinkedList() {
            Node *current = head;
            while ( current != nullptr ) {
                Node *last = current;
                current = current->next;
                delete last;
            }
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        
        // Find the index of a particular item
        // Return -1 if it is not found
        int find(const T &item) {
            // YOUR CODE HERE
            int iterator = 0;

            // For some reason this had a read access violation, and it makes me sad, I've tried everything else
            // and that also has read access violations, so I'm just gonna have to work around that :/
            for (Node* current = head; current != nullptr; current = current->next, iterator++)
                if (current->data == item) return iterator;

            return -1;
        }
        
        // Get the item at a particular index
        T &get(int index) {
            assert(index < count); // can't insert off end
            assert(index >= 0); // no negative indices
            // YOUR CODE HERE
            Node *current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
            return current->data;
        }
        
        // Insert at the beginning of the collection
        void insertAtBeginning(const T &item) {
            // YOUR CODE HERE
            Node *newNode = new Node(item);
            newNode->next = head;
            head = newNode;
            count++;
        }
        
        // Insert at the end of the collection
        void insertAtEnd(const T &item) {
            // YOUR CODE HERE
            
            Node *newNode = new Node(item);
            if (count == 0) {
                head = newNode;
                tail = newNode;
                count++;
                return;
            }
            tail->next = newNode;
            tail = newNode;
            count++;
        }
        
        // Insert at a specific index
        void insert(const T &item, int index) {
            assert(index <= count); // can't insert off end
            assert(index >= 0); // no negative indices
            if (index == 0) {
                insertAtBeginning(item);
                return;
            }
            if (index == count) {
                insertAtEnd(item);
                return;
            }
            int location = 0;
            for (Node *current = head; current != nullptr; current = current->next) {
                if (location == (index-1)) {
                    Node *after = current->next;
                    Node *thing = new Node(item);
                    current->next = thing;
                    thing->next = after;
                    count++;
                    return;
                }
                location++;
            }
        }
        
        // Remove the item at the beginning of the collection
        void removeAtBeginning() {
            assert(count > 0);
            // YOUR CODE HERE
            Node *temp = head;
            head = head->next;
            delete temp;
            count--;
        }
        
        // Remove the item at the end of the collection
        void removeAtEnd() {
            assert(count > 0);
            // YOUR CODE HERE
            Node *current = head;

            //move current to the second to last node in the list
            for (int i = 0; i < count; i++, current = current->next);
            delete current;
            current = head;
            for (int i = 0; i < count - 1; i++, current = current->next);
            tail = current;
            count--;
        }
        
        // Remove the item at a specific index
        void removeAt(int index) {
            assert(index >= 0);
            assert(index < count);
            assert(count > 0);
            if (index == 0) {
                removeAtBeginning();
                return;
            }
            if (index == (count - 1)) {
                removeAtEnd();
                return;
            }
            
            int location = 0;
            for (Node *current = head; current != nullptr; current = current->next) {
                if (location == (index-1)) {
                    Node *after = current->next->next;
                    delete (current->next);
                    current->next = after;
                    count--;
                    return;
                }
                location++;
            }
        }
        
    protected:
        using Collection<T>::count;
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        
        class Node {
            friend class LinkedList;
        public:
            Node(const T &thing): data(thing), next(nullptr) {};
        private:
            T data;
            Node *next;
        };
    };
}

#endif /* linkedlist_hpp */
