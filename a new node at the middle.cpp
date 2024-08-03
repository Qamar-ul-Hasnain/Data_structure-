#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtMiddle(Node*& head, int value) {
    Node* newNode = createNode(value);
    queue<Node*> nodeQueue;

    Node* current = head;
    while (current != NULL) {
        nodeQueue.push(current);
        current = current->next;
    }

    int size = nodeQueue.size();
    int middleIndex = size / 2;

    if (size % 2 == 0) {
        middleIndex--;
    }

    current = head;
    for (int i = 0; i < middleIndex; ++i) {
        current = current->next;
    }

    Node* nextNode = current->next;
    current->next = newNode;
    newNode->next = nextNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int testData[] = {7, 5, 3, 1};
    int testDataSize = sizeof(testData) / sizeof(testData[0]);

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

    cout << "Original list:" << endl;
    displayList(head);

    insertAtMiddle(head, 9);
    cout << "Singly Linked List: after insert 9 in the middle of the said list" << endl;
    displayList(head);

    insertAtMiddle(head, 11);
    cout << "Singly Linked List: after insert 11 in the middle of the said list" << endl;
    displayList(head);

    // Freeing the allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

