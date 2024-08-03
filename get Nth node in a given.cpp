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

int getNthNodeValue(Node* head, int position) {
    queue<Node*> nodeQueue;
    Node* current = head;

    while (current != NULL) {
        nodeQueue.push(current);
        current = current->next;
    }

    int size = nodeQueue.size();
    int targetIndex = size - position;

    if (targetIndex < 0 || position <= 0 || position > size) {
        return -1; // Indicates an error or an invalid position
    }

    int currentIndex = 0;
    while (!nodeQueue.empty()) {
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        if (currentIndex == targetIndex) {
            return currentNode->data;
        }

        currentIndex++;
    }

    return -1; // Indicates an error (should not reach this point)
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

    int positions[] = {1, 2, 3, 4};
    int positionsSize = sizeof(positions) / sizeof(positions[0]);

    for (int i = 0; i < positionsSize; ++i) {
        int position = positions[i];
        int value = getNthNodeValue(head, position);

        cout << "Position: " << position << endl;
        cout << "Value: " << value << endl;
    }

   
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

