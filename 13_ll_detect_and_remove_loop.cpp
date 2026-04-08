#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    Node* getHead() { return head; }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void createLoop(int pos) {
        if (pos <= 0 || !head) return;

        Node* loopNode = nullptr;
        Node* temp = head;
        int idx = 1;

        while (temp->next) {
            if (idx == pos) loopNode = temp;
            temp = temp->next;
            idx++;
        }

        if (idx == pos) loopNode = temp;
        if (loopNode) temp->next = loopNode;
    }

    bool detectAndRemoveLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                removeLoop(slow);
                return true;
            }
        }
        return false;
    }

    void removeLoop(Node* meet) {
        Node* ptr1 = head;

        if (meet == head) {
            while (meet->next != head) meet = meet->next;
            meet->next = nullptr;
            return;
        }

        Node* ptr2 = meet;
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = nullptr;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    LinkedList list;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.append(x);
    }

    int pos;
    cout << "Enter loop start position (1-based, 0 for no loop): ";
    cin >> pos;
    list.createLoop(pos);

    bool hadLoop = list.detectAndRemoveLoop();

    if (hadLoop) {
        cout << "Loop detected and removed.\n";
    } else {
        cout << "No loop detected.\n";
    }

    cout << "Final linked list: ";
    list.print();

    return 0;
}
