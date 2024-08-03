#include <iostream>

using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to display the linked list in reverse order
void displayReverseList(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    // Reverse the linked list
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Display the reversed linked list
    cout << "Reverse Linked list: ";
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Test Data
    int testData[] = {11, 9, 7, 5, 3, 1};
    int testDataSize = sizeof(testData) / sizeof(testData[0]);

    // Creating the linked list
    for (int i = 0; i < testDataSize; ++i) {
        int value = testData[i];
        Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Displaying the original linked list
    cout << "Original Linked list: ";
    displayList(head);

    // Displaying the linked list in reverse order
    displayReverseList(head);

    // Freeing the allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

