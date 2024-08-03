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

    // Displaying the linked list
    cout << "The list contains the data entered: ";
    displayList(head);

    // Freeing the allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

