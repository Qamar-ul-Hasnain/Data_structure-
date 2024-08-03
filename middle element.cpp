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

int findMiddleElement(Node* head) {
    stack<Node*> nodeStack;

    while (head != NULL) {
        nodeStack.push(head);
        head = head->next;
    }

    int size = nodeStack.size();
    int middleIndex = size / 2;
    int currentIndex = 0;

    while (!nodeStack.empty()) {
        Node* currentNode = nodeStack.top();
        nodeStack.pop();

        if (currentIndex == middleIndex) {
            return currentNode->data;
        }

        currentIndex++;
    }

    return -1; // Indicates an error or an empty list
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int testData1[] = {7, 5, 3, 1};
    int testDataSize1 = sizeof(testData1) / sizeof(testData1[0]);

    for (int i = 0; i < testDataSize1; ++i) {
        int value = testData1[i];
        Node* newNode = createNode(value);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cout << "Original list:" << endl;
    displayList(head1);

    int middle1 = findMiddleElement(head1);
    cout << "Middle element of the said list: " << middle1 << endl;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    int testData2[] = {9, 7, 5, 3, 1};
    int testDataSize2 = sizeof(testData2) / sizeof(testData2[0]);

    for (int i = 0; i < testDataSize2; ++i) {
        int value = testData2[i];
        Node* newNode = createNode(value);

        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    cout << "Original list:" << endl;
    displayList(head2);

    int middle2 = findMiddleElement(head2);
    cout << "Middle element of the said list: " << middle2 << endl;

    // Freeing the allocated memory
    while (head1 != NULL) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != NULL) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}

