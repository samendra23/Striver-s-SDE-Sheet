//Reversing a linked list
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

//Brute -- TC = O(2n); SC = O(n)
// Node* reverseLinkedList(Node* head){
//     Node* temp = head;
//     stack<int> st;

//     while(temp){
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     temp = head;
//     while(temp){
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }

//     return head;
// }

//Better -- TC = O(n); SC = O(1)
Node* reverseLinkedList(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head = prev;
    return head;
}

//Optimal -- TC = O(); SC = O()


//Main
// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}