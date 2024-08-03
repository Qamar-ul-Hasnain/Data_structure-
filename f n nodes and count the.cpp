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


int countNodesUsingStack(Node* head) {
    stack<Node*> nodeStack;

  
    while (head != NULL) {
        nodeStack.push(head);
        head = head->next;
    }

    int count = nodeStack.size();

    return count;
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

   
    int numberOfNodes = countNodesUsingStack(head);

   
    cout << "Number of node " << numberOfNodes << endl;

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

