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

void insertAtPosition(Node*& head, int position, int value) {
    Node* newNode = createNode(value);
    stack<Node*> nodeStack;

    Node* current = head;
    while (current != NULL) {
        nodeStack.push(current);
        current = current->next;
    }

    int size = nodeStack.size();

    if (position <= 0 || position > size + 1) {
        cout << "Invalid position." << endl;
        return;
    }

    current = head;
    for (int i = 1; i < position - 1; ++i) {
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

    insertAtPosition(head, 1, 12);
    cout << "Position: 1, Value: 12" << endl;
    cout << "Updated list:" << endl;
    displayList(head);

    insertAtPosition(head, 4, 14);
    cout << "Position: 4, Value: 14" << endl;
    cout << "Updated list:" << endl;
    displayList(head);

    insertAtPosition(head, 7, 18);
    cout << "Position: 7, Value: 18" << endl;
    cout << "Updated list:" << endl;
    displayList(head);

   
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

