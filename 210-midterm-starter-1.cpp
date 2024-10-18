#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdlib> 
using namespace std;


struct Node {

    string data; 

    Node* prev;

    Node* next;

    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
}; 

// DoublyLinkedList class is created 
class DoublyLinkedList {
private:

    Node* head; // Points to the head of the linked list
    Node* tail; // Points to the end of the linked list 

public:
    DoublyLinkedList() {  // Class constructor initializes head and tail of linked list
        
    head = nullptr;
        
    tail = nullptr;
    
    } 

    void push_back(string n) {
        Node* newNode = new Node(n);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(string n) {
        Node* newNode = new Node(n);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "Line is empty." << endl;
            return;
        }

        Node * temp = head;

        head = head->next; 

        if (head) {
            
            head->prev = nullptr;
        }
            
        else
            head = tail = nullptr;
        
        delete temp;
    }

    void pop_back() {
        
        if (!tail) {
            
            cout << "Line is empty." << endl;
            return;
        }
        Node* temp = tail;

        tail = tail->prev; 
        
        if (tail) {
            
            tail->next = nullptr;
        }
            
        else
            head = tail = nullptr;
        
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* current = head;
        
        while (current) {
            
            cout << current->data << " ";
            current = current->next;
            
        }
        cout << endl;
    }

    Node* random_customer() {

        int count = 0; 

        Node* current = head; 

        while (current) {

            count++; 

            current = current->next; 
        }

        int random = rand() % count; 

        current = head; 

        for (int i = 0; i < random; i++) {

            current->next; 
        }
        
        return current;
    }

    
};

int main() {

    DoublyLinkedList list; 

    list.push_back(1);
    list.push_back(2); 
    list.push_back(3);
    list.push_back(4); 
    list.push_back(5); 

    cout << "list";

    list.print(); 

    cout << "Other element"; 

    list.every_other_element();     
    return 0;
}
