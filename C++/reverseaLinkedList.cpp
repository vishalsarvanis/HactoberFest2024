#include <iostream>

using namespace std;

// Define the Node structure
class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseLinkedList(Node *head) {
    Node* temp = head;  
    Node* prev = nullptr;  // Initialize previous pointer to nullptr

    while (temp != nullptr) {  
        Node* front = temp->next;  // Store the next node
        temp->next = prev;          // Reverse the link
        prev = temp;                // Move prev to current node
        temp = front;               // Move to the next node
    }

    return prev;  // New head of the reversed list
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to free the linked list memory
void deleteLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;  // Free the memory
    }
}

int main() {
    // Create a linked list: 1 -> 3 -> 2 -> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    // Free the memory allocated for the linked list
    deleteLinkedList(head);

    return 0;
}
