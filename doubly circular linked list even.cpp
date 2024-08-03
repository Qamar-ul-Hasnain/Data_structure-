#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};

//  new node at the end doubly circular linked list
void insertNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}


void displayEvenNodes(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    int i = 1;

    do {
        if (i % 2 == 0) {
            cout << current->data << " ";
        }
        current = current->next;
        i++;
    } while (current != head);
}

int main() {
    Node* head = NULL;

   
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    
    cout << "Even number is ";
    displayEvenNodes(head);

    return 0;
}

