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

    void reorder() {
        if (!head || !head->next || !head->next->next) return;

        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = nullptr;

        Node* prev = nullptr;
        while (second) {
            Node* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        Node* first = head;
        second = prev;
        while (second) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
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

    list.reorder();

    cout << "Reordered list: ";
    list.print();

    return 0;
}
