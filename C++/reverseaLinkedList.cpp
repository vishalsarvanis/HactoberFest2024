#include <iostream>

using namespace std;


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


Node* reverseLinkedList(Node *head) {
    Node* temp = head;  
    Node* prev = nullptr; 

    while (temp != nullptr) {  
        Node* front = temp->next;  
        temp->next = prev;         
        prev = temp;               
        temp = front;               
    }

    return prev;  
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;  
    }
}

int main() {
 
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

   
    deleteLinkedList(head);

    return 0;
}
