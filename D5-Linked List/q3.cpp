//RMerge two sorted Linked Lists
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

//Brute -- TC = O(n1+n2) + O(nlogn) + O(n); SC = O(n) + O(n)
Node* sortTwoLinkedLists(Node* first, Node* second) {
    vector<int> ans;
    Node* tempf = first;
    Node* temps = second;

    while (tempf) {
        ans.push_back(tempf->data);
        tempf = tempf->next;
    }

    while (temps) {
        ans.push_back(temps->data);
        temps = temps->next;
    }

    sort(ans.begin(), ans.end());

    Node* head = new Node(ans[0]);
    Node* temp = head;

    for (int i = 1; i < ans.size(); i++) {
        temp->next = new Node(ans[i]);
        temp = temp->next;
    }

    return head;
}

//Optimal -- TC = O(n); SC = O(1)


//Optimal 2 -- TC = O(n); SC = O(1)


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
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}