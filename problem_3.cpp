#include<bits/stdc++.h>
using namespace std;
class  Node {
    public :
    int data;
    Node * next;
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
    public : 
    Node * head;
    LinkedList() : head(NULL) {}

    void insert(int value){
        Node * newNode = new Node(value);
        if(head == NULL){
            head = newNode;
        }
        else {
            Node * temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            
        }
    }
    void printMiddle(){
        if(head == NULL) return;
        Node * slow = head;
        Node * fast = head;
        while(fast  !=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
         if (fast == NULL) {
            Node* temp = head;
            while (temp->next != slow) {
                temp = temp->next;
            }
            std::cout << temp->data << " ";
        }
        std::cout << slow->data << std::endl;
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
int main () {
     LinkedList list;
    int value;

    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        list.insert(value);
    }

    list.printMiddle();
    return 0;
}