#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; // We create four constant integer variables 

// DoublyLinkedList class is created 
class DoublyLinkedList {
private:
    struct Node { // Struct named 'Node' is created which declares elements for the linked list
        int data; 
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) { // Consturctor for Node struct is created 
            data = val; 
            prev = p; // prev pointer is initialized with p
            next = n; // next pointer is initialized with p 
        }
    };

    Node* head; // Points to the head of the linked list
    Node* tail; // Points to the end of the linked list 

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; } // Class constructor initializes head and tail of linked list

    void insert_after(int value, int position) { // Function which creates a node if a position is specified 
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value); // New node is created 
        if (!head) { // If statement stating if the head is empty then initialize the head and tail with the new node
            head = tail = newNode;
            return;
        }

        Node* temp = head; // Temporary node is created 
        for (int i = 0; i < position && temp; ++i) // Temporary node and position traverse the linked list
            temp = temp->next;

        if (!temp) { // If the temporary node is 
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
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
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
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
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void every_other_element() {

        Node* current = head; 

        bool skip = false; 

        while (current) {

            if (!skip) {

                 cout << current->data << " "; 
            }

            skip = !skip; 

            current = current->next; 
              
        }
           cout << endl; 
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