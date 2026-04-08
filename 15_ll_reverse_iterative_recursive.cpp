#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    Node* reverseRecursiveUtil(Node* node) {
        if (!node || !node->next) return node;
        Node* newHead = reverseRecursiveUtil(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

public:
    LinkedList() : head(nullptr) {}

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

    void reverseIterative() {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    void reverseRecursive() {
        head = reverseRecursiveUtil(head);
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

    vector<int> values(n);
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    LinkedList list1;
    LinkedList list2;
    for (int x : values) {
        list1.append(x);
        list2.append(x);
    }

    list1.reverseIterative();
    cout << "Iterative Reverse: ";
    list1.print();
    cout << "Time Complexity: O(n)\n";
    cout << "Space Complexity: O(1)\n";

    list2.reverseRecursive();
    cout << "Recursive Reverse: ";
    list2.print();
    cout << "Time Complexity: O(n)\n";
    cout << "Space Complexity: O(n)\n";

    return 0;
}
