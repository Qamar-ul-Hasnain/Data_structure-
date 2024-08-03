#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (!head) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

void insertionSort(Node*& head) {
    if (!head || head->next == head) {
        return; 
    }

    Node* sorted = NULL;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        Node* prev = NULL;

        for (Node* temp = sorted; temp; temp = temp->next) {
            if (current->data <= temp->data) {
                break;
            }
            prev = temp;
        }

        if (!prev) {
            sorted = current;
        } else {
            prev->next = current;
        }

        current->prev = prev;
        current->next = sorted->next;
        sorted->next = current;

        if (current->next == head) {
            head = sorted;
        }

        current = next;
    }
}

void displayList(Node* head) {
    if (!head) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node* head = NULL;

   
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 5);
    insertNode(head, 30);
    insertNode(head, 15);

    cout << "Original list" << endl;
    displayList(head);

    insertionSort(head);

    cout << "Sorted list" << endl;
    displayList(head);

    return 0;
}

