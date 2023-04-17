#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int getMiddle(Node* head) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}

int main() {
    // Creating the linked list
    Node* head = new Node;
    head->data = 1;
    head->next = new Node;
    head->next->data = 2;
    head->next->next = new Node;
    head->next->next->data = 3;
    head->next->next->next = new Node;
    head->next->next->next->data = 4;
    head->next->next->next->next = new Node;
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    // Finding the middle element
    int middle = getMiddle(head);

    // Printing the middle element
    cout << "The middle element is: " << middle << endl;

    return 0;
}
