#include <iostream>
using namespace std;

// Definition of a structure representing a Node in the linked list
struct Node {
  int data;      // Data stored in the node
  Node *next;    // Pointer to the next node in the list
};

// Global variable representing the head of the linked list
Node *head = NULL;

// Function to create a linked list based on user input
void Create() {
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int data;
    cout << "Enter data for node " << i + 1 << ": ";
    cin >> data;

    // Create a new node with the entered data
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    // Otherwise, traverse to the end of the list and append the new node
    if (head == NULL) {
      head = newNode;
    } else {
      Node *current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = newNode;
    }
  }
}

// Function to display the elements of the linked list
void Display() {
  Node *current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

// Function to reverse the linked list and display it
void DisplayReverse() {
  if (head == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;

  // Reverse the links between nodes
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  // Update the head to the new first node (previously the last)
  head = prev;

  // Display the reversed list
  cout << "Reverse list: ";
  Display();
}

// Function to display the linked list in reverse using recursion
void DisplayRecursive(Node *ptr) {
  if (ptr == NULL) {
    return;
  }

  // Recursively call the function for the next node before printing current data
  DisplayRecursive(ptr->next);
  cout << ptr->data << " ";
}

// Function to insert a new node at the beginning of the list
void InsertAtStart(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = head;

  // Set the new node as the head of the list
  head = newNode;
}

// Function to insert a new node at the end of the list
void InsertAtEnd(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  // If the list is empty, set the new node as the head
  // Otherwise, traverse to the end of the list and append the new node
  if (head == NULL) {
    head = newNode;
  } else {
    Node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Function to insert a new node at a specific position in the list
void InsertAtN(int data, int n) {
  if (n < 1) {
    cout << "Invalid position" << endl;
    return;
  }

  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  int position = 1;
  Node *current = head;

  // Traverse to the specified position or the end of the list
  while (current != NULL && position < n) {
    current = current->next;
    position++;
  }

  // If the specified position is found, insert the new node
  if (position == n) {
    newNode->next = current->next;
    current->next = newNode;
  } else {
    cout << "Invalid position" << endl;
  }
}

// Function to delete a node at a specific position in the list
void DeleteAtN(int n) {
  if (n < 1) {
    cout << "Invalid position" << endl;
    return;
  }

  int position = 1;
  Node *current = head;
  Node *prev = NULL;

  // Traverse to the specified position or the end of the list
  while (current != NULL && position < n) {
    prev = current;
    current = current->next;
    position++;
  }

  // If the specified position is found, delete the node
  if (position == n) {
    if (prev == NULL) {
      head = current->next;
    } else {
      prev->next = current->next;
    }
    delete current;
  } else {
    cout << "Invalid position" << endl;
  }
}

// Function to reverse the linked list
void ReverseList() {
  if (head == NULL || head->next == NULL) {
    return;
  }

  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;

  // Reverse the links between nodes
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  // Set the head to the new first node (previously the last)
  head = prev;
}

// The main function where the program starts execution
int main() {
  // Create a linked list based on user input
  Create();

  // Display the original list
  cout << "List: ";
  Display();

  // Reverse the list and display it
  cout << "Display in reverse: ";
  DisplayReverse();

  // Display the reversed list using recursion
  cout << "Display with recursion: ";
  if (head != NULL) {
    DisplayRecursive(head);
  }
  cout << endl;

  // Get data from the user and insert a new node at the start
  int data;
  cout << "Enter data to insert at start: ";
  cin >> data;
  InsertAtStart(data);

  // Display the list after insertion at the start
  cout << "List: ";
  Display();

  // Get data from the user and insert a new node at the end
  cout << "Enter data to insert at end: ";
  cin >> data;
  InsertAtEnd(data);

  // Display the list after insertion at the end
  cout << "List: ";
  Display();

  // Get data and position from the user and insert a new node at a specific position
  int position;
  cout << "Enter data and position to insert: ";
  cin >> data >> position;
  InsertAtN(data, position);

  // Display the list after insertion at a specific position
  cout << "List: ";
  Display();

  // Get the position from the user and delete the node at that position
  cout << "Enter position to delete: ";
  cin >> position;
  DeleteAtN(position);

  // Display the list after deletion at a specific position
  cout << "List: ";
  Display();

  // Reverse the entire list
  ReverseList();

  // Display the list after reversing it
  cout << "List after reversing: ";
  Display();

  // The program terminates with a return value of 0
  return 0;
}

