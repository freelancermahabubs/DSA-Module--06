#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool containsDuplicate() {
        if (head == NULL) return false;
        
        bool seen[101] = {false};  
        Node* temp = head;
        while (temp != NULL) {
            if (seen[temp->data]) {
                return true;
            }
            seen[temp->data] = true;
            temp = temp->next;
        }
        return false;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList list;
    int value;

    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        list.insert(value);
    }

    if (list.containsDuplicate()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}