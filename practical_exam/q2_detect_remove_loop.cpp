// Detect and Remove Loop in Linked List (Floyd's Cycle Detection)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectAndRemoveLoop(Node *head)
{
    if (!head || !head->next)
        return false;

    Node *slow = head;
    Node *fast = head;

    // Detect loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return false;

    // Find loop start
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node of loop
    Node *ptr = slow;
    while (ptr->next != slow)
    {
        ptr = ptr->next;
    }

    // Remove loop
    ptr->next = nullptr;

    return true;
}

void print(Node* head) {
    for (int i = 0; head && i < 20; head = head->next, i++) {
        cout << head->data;
        if (head->next) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    // Build: 1 -> 2 -> 3 -> 4 -> 5 -> 6, loop: 6->3
    Node* n1 = new Node(1); Node* n2 = new Node(2); Node* n3 = new Node(3);
    Node* n4 = new Node(4); Node* n5 = new Node(5); Node* n6 = new Node(6);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6;
    n6->next = n3; // create loop

    bool removed = detectAndRemoveLoop(n1);
    cout << "Loop detected and removed: " << (removed ? "Yes" : "No") << "\n";
    cout << "List after removal: "; print(n1);

    // No loop case
    Node* m1 = new Node(10); Node* m2 = new Node(20); Node* m3 = new Node(30);
    m1->next = m2; m2->next = m3;
    cout << "No-loop case detected: " << (detectAndRemoveLoop(m1) ? "Yes" : "No") << "\n";
}
