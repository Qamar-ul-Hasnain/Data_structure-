#include <iostream>
#include <stack>

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

void deleteFirstNode(Node*& head) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete first node." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int testData[] = {13, 11, 9, 7, 5, 3, 1};
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

    cout << "Original Linked list:" << endl;
    displayList(head);

    cout << "Delete first node of Singly Linked List:" << endl;
    deleteFirstNode(head);
    displayList(head);

  
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

