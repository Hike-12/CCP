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

    void reverseInGroups(int k) {
        if (k <= 1 || !head) return;

        Node dummy(0);
        dummy.next = head;
        Node* prevGroupEnd = &dummy;

        while (true) {
            Node* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            Node* groupStart = prevGroupEnd->next;
            Node* nextGroupStart = kth->next;

            Node* prev = nextGroupStart;
            Node* curr = groupStart;

            while (curr != nextGroupStart) {
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        head = dummy.next;
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

    int n, k;
    cout << "Enter number of nodes: ";
    cin >> n;

    LinkedList list;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.append(x);
    }

    cout << "Enter K: ";
    cin >> k;

    list.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    list.print();

    return 0;
}
