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

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);

    stack<Node*> nodeStack;

    while (head != NULL) {
        nodeStack.push(head);
        head = head->next;
    }

    Node* newHead = newNode;
    while (!nodeStack.empty()) {
        newNode = nodeStack.top();
        nodeStack.pop();
        newNode->next = newHead;
        newHead = newNode;
    }

    return newHead;
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

    cout << "Original Linked list: ";
    displayList(head);

    head = insertAtBeginning(head, 0);

    cout << "Insert a new node at the beginning of a Singly Linked List: ";
    displayList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

