// Reverse Linked List in Groups of K (Optimal Iterative)
#include <initializer_list>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *reverseKGroup(Node *head, int k)
{
    if (!head || k <= 1)
        return head;

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *groupPrev = dummy;

    while (true)
    {
        Node *kth = groupPrev;

        for (int i = 0; i < k && kth != nullptr; i++)
        {
            kth = kth->next;
        }

        if (kth == nullptr)
            break;

        Node *groupNext = kth->next;

        Node *prev = groupNext;
        Node *curr = groupPrev->next;

        while (curr != groupNext)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        Node *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    Node *res = dummy->next;
    delete dummy;
    return res;
}

Node *build(initializer_list<int> vals)
{
    Node *dummy = new Node(0);
    Node *cur = dummy;
    for (int v : vals)
    {
        cur->next = new Node(v);
        cur = cur->next;
    }
    return dummy->next;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *list = build({1, 2, 3, 4, 5, 6, 7, 8});
    cout << "Input:  ";
    print(list);
    list = reverseKGroup(list, 3);
    cout << "k=3:    ";
    print(list);

    list = build({1, 2, 3, 4, 5});
    list = reverseKGroup(list, 2);
    cout << "k=2:    ";
    print(list);
}