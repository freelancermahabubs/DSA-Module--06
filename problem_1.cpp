#include<bits/stdc++.h>
using namespace std;
class Node {
    public: 
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
class LinkedList {
    public: 
    Node * head;
    LinkedList() : head(NULL) {}
    void insert(int value){
        Node * newNode = new Node(value);
        if(head == NULL){
            head = newNode;
        }
        else {
            Node * temp = head;
            while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = newNode;
    }}
    int getSize () {
        int size = 0;
        Node * temp = head;
        while(temp != NULL){
         size++;
         temp = temp->next;
    }
    return size;
    }
    ~LinkedList(){
        Node* temp = head;
        while(temp != NULL){
            Node * next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main (){
    LinkedList list;
    int value;
    while(true){
        std: cin>> value ;
        if(value ==-1){
            break;
        }
        list.insert(value);
    }
     std::cout << list.getSize() << std::endl;
return 0;
}