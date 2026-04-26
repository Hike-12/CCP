// Reverse Linked List in Groups of K
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Check if k nodes are available
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head;
        temp = temp->next;
    }

    // Reverse k nodes
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // head is now the tail of reversed group
    head->next = reverseKGroup(curr, k);
    return prev;
}

Node* build(initializer_list<int> vals) {
    Node* dummy = new Node(0);
    Node* cur = dummy;
    for (int v : vals) { cur->next = new Node(v); cur = cur->next; }
    return dummy->next;
}

void print(Node* head) {
    while (head) { cout << head->data; if (head->next) cout << " -> "; head = head->next; }
    cout << "\n";
}

int main() {
    Node* list = build({1, 2, 3, 4, 5, 6, 7, 8});
    cout << "Input:  "; print(list);
    list = reverseKGroup(list, 3);
    cout << "k=3:    "; print(list);

    list = build({1, 2, 3, 4, 5});
    list = reverseKGroup(list, 2);
    cout << "k=2:    "; print(list);
}
