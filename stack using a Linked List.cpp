#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class Stack {
  Node* head;

public:
  Stack() {
    head = NULL;
  }

  int size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
      count++;
      temp = temp->next;
    }
    return count;
  }

  bool isEmpty() {
    return head == NULL;
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }

    return head->data;
  }

  void push(int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void display() {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return;
    }

    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  Stack stack;

  int choice;
  do {
    cout << "\nStack Operations Menu" << endl;
    cout << "1. Size" << endl;
    cout << "2. Is Empty" << endl;
    cout << "3. Top" << endl;
    cout << "4. Push" << endl;
    cout << "5. Pop" << endl;
    cout << "6. Display" << endl;
    cout << "7. Exit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        cout << "Stack size: " << stack.size() << endl;
        break;
      }

      case 2: {
        if (stack.isEmpty()) {
          cout << "Stack is empty" << endl;
        } else {
          cout << "Stack is not empty" << endl;
        }
        break;
      }

      case 3: {
        cout << "Top element " << stack.top() << endl;
        break;
      }

      case 4: {
        int data;
        cout << "Enter data to push ";
        cin >> data;
        stack.push(data);
        break;
      }

      case 5: {
        stack.pop();
        break;
      }

      case 6: {
        stack.display();
        break;
      }

      case 7: {
        cout << "Exiting the program" << endl;
        break;
      }

      default: {
        cout << "Invalid choice" << endl;
        break;
      }
    }
  } while (choice != 7);

  return 0;
}

