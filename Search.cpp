#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


int findIndexInLinkedList(ListNode* head, int X) {
    int index = 0;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (current->val == X) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    return -1;
}


void processLinkedListSearch() {
    int T;
    cin >> T; 
    
    vector<int> results;
    
    for (int t = 0; t < T; ++t) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        

        int value;
        while (cin >> value && value != -1) {
            ListNode* new_node = new ListNode(value);
            if (head == nullptr) {
                head = new_node;
                tail = head;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        

        int X;
        cin >> X;
        
 
        int index = findIndexInLinkedList(head, X);
        results.push_back(index);
        

        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    for (int result : results) {
        cout << result << endl;
    }
}

int main() {
    processLinkedListSearch();
    return 0;
}
