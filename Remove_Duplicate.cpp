#include <iostream>
#include <limits>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};


Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
        return newNode;
    }
    
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}


int findDifference(Node* head) {
    if (head == nullptr) {
        return 0; 
    }
    
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();
    
    Node* current = head;
    

    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    

    return maxVal - minVal;
}

int main() {
    Node* head = nullptr;
    int value;
    

    while (true) {
        cin >> value;
        if (value == -1)
            break;
        head = insertAtTail(head, value);
    }
    

    int difference = findDifference(head);
    cout << difference << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
