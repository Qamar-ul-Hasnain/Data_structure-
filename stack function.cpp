#include <iostream>

using namespace std;

#define n 100

int top = -1;
int stack[n];

void push(int data) {
  if (top >= n - 1) {
    cout << "Stack Overflow" << endl;
    return;
  }

  top++;
  stack[top] = data;
}

int pop() {
  if (top == -1) {
    cout << "Stack Underflow" << endl;
    return -1;
  }

  int data = stack[top];
  top--;
  return data;
}

int peek() {
  if (top == -1) {
    cout << "Stack is empty" << endl;
    return -1;
  }

  return stack[top];
}

bool isEmpty() {
  return top == -1;
}

void display() {
  if (top == -1) {
    cout << "Stack is empty!" << endl;
    return;
  }

  for (int i = top; i >= 0; i--) {
    cout << stack[i] << " ";
  }
  cout << endl;
}

void sortStack() {
  int temp;
  for (int i = 0; i < top; i++) {
    for (int j = i + 1; j <= top; j++) {
      if (stack[i] > stack[j]) {
        temp = stack[i];
        stack[i] = stack[j];
        stack[j] = temp;
      }
    }
  }
}

int main() {
  int choice;

  do {
    cout << "\nStack Operations Menu" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Check Empty" << endl;
    cout << "5. Display" << endl;
    cout << "6. Sort Stack" << endl;
    cout << "7. Exit" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        int data;
        cout << "Enter data to push: ";
        cin >> data;
        push(data);
        break;
      }

      case 2: {
        int data = pop();
        if (data != -1) {
          cout << "Popped element: " << data << endl;
        }
        break;
      }

      case 3: {
        int data = peek();
        if (data != -1) {
          cout << "Top element: " << data << endl;
        }
        break;
      }

      case 4: {
        if (isEmpty()) {
          cout << "Stack is empty" << endl;
        } else {
          cout << "Stack is not empty" << endl;
        }
        break;
      }

      case 5: {
        display();
        break;
      }

      case 6: {
        sortStack();
        cout << "Stack sorted successfully" << endl;
        break;
      }

      case 7: {
        cout << "Exit the program" << endl;
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

