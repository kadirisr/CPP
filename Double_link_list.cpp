#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void addNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to remove a node from the list
    void removeNode(int data) {
        if (head == nullptr) {
            cout << "List is empty. Cannot remove." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                if (temp == head) {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    delete temp;
                    return;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != nullptr)
                        temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        }

        cout << "Element " << data << " not found in the list." << endl;
    }

    // Function to display the list forward
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the list backward
    void displayBackward() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // unit test for Adding nodes
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    // unit test for displaying the list forward
    cout << "List forward: ";
    list.displayForward();

    // unit test for displaying the list backward
    cout << "List backward: ";
    list.displayBackward();

    // unit test for removing a node for the given data 
    list.removeNode(3);

    // unit test for displaying the list forward after removal
    cout << "List forward after removing node with data 3: ";
    list.displayForward();

    return 0;
}
