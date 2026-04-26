// LRU Cache using Doubly Linked List + HashMap
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail; // dummy head and tail

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        cache.clear();
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        insertFront(node);
        return node->val;
    }

    void put(int key, int val) {
        if (capacity <= 0) return;
        if (cache.count(key)) {
            cache[key]->val = val;
            remove(cache[key]);
            insertFront(cache[key]);
        } else {
            if ((int)cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, val);
            cache[key] = node;
            insertFront(node);
        }
    }

    void print() {
        Node* cur = head->next;
        cout << "Cache (MRU->LRU): ";
        while (cur != tail) { cout << "[" << cur->key << "=" << cur->val << "] "; cur = cur->next; }
        cout << "\n";
    }
};

int main() {
    LRUCache lru(3);
    lru.put(1, 10); lru.put(2, 20); lru.put(3, 30);
    lru.print();

    cout << "get(1)=" << lru.get(1) << "\n"; lru.print();
    lru.put(4, 40); // evicts key 2
    lru.print();
    cout << "get(2)=" << lru.get(2) << " (evicted)\n";
    cout << "get(3)=" << lru.get(3) << "\n";
    lru.print();
}
