//Find middle element in a Linked List
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

//Brute -- TC = O(n + n/2); SC = O(1)
// Node *findMiddle(Node *head) {
//     // Write your code here
//     int cnt = 0;
//     Node* temp = head;
//     while(temp){
//         cnt++;
//         temp = temp->next;
//     }

//     cnt = cnt/2 + 1;
//     temp = head;
//     for(int i=1; i<cnt; i++){
//         temp = temp->next;
//     }

//     return temp;
// }

//Optimal -- TC = O(n/2); SC = O(1)
// Node *findMiddle(Node *head) {
//     Node* slow = head;
//     Node* fast = head;
//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }

//Optimal -- faster
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

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
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}