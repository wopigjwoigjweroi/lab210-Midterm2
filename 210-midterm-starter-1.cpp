// COMSC-210 | Midterm#2 | Jeremiah Ortiz
#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdlib> 
#include <string>
using namespace std;

struct Node {

    string data;

    Node* prev;

    Node* next;

    Node(string d) : data(d), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class is created 
class DoublyLinkedList {

public:

    Node* head; // Points to the head of the linked list
    Node* tail; // Points to the end of the linked list 

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

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

        Node* temp = head;

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


    void remove_customer(Node* customer) {

        if (customer == head) {

            pop_front();

        }
        else if (customer == tail) {

            pop_back();

        }
        else {

            customer->prev->next = customer->next;

            customer->next->prev = customer->prev;

            delete customer;
        }
    }
};


vector<string> names(const string& filename) {

    vector<string> nameList;

    fstream file("names.txt"); 

        string names;

    while (getline(file, names)) {

        nameList.push_back(names);
    }

    return nameList;
}

int main() {

    DoublyLinkedList l;

    srand(time(0));

    vector<string> nameList = names("names.txt"); 

        cout << "Store opens: \n";

    for (int i = 0; i < 5; i++) {

        string nameCustomer = nameList[rand() % nameList.size()];

        cout << nameCustomer << " joins the line\n"; 

        l.push_back(nameCustomer); 

    }

    for (int min = 1; min <= 20; min++) {

        cout << "Time step #" << min << ":\n"; 

        if (rand() % 100 < 40 && l.head) {

            cout << l.head->data << "is served\n"; 
            l.pop_front(); 
        }

        if (rand() % 100 < 60) {

            string nameCustomer = nameList[rand() % nameList.size()];

            cout << nameCustomer << "joins the line\n"; 

            l.push_back(nameCustomer); 
        }

        if (rand() % 100 < 20 && l.tail) {

            cout << l.tail->data << " (at the rear) left the line\n"; 
            l.pop_back(); 
        }

        if (rand() % 100 < 10 && l.head) {

            Node* randomCustomer = l.random_customer(); 

            if (randomCustomer) {

                cout << randomCustomer->data << " left the line\n"; 

                l.remove_customer(randomCustomer); 
            }

        }

        if (rand() % 100 < 10) {

            string VIP = nameList[rand() % nameList.size()]; 

            cout << VIP << " (VIP) joins the front of the line\n"; 

            l.push_front(VIP); 
        }

        cout << "Resulting line: \n";

        l.print(); 
    }

    return 0;
}
