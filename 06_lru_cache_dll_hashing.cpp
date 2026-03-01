// LRU Cache (Doubly Linked List + Hashing)
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addFront(node);
    }

    Node* removeLeastRecent() {
        Node* node = tail->prev;
        if (node == head) return nullptr;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        Node* node = it->second;
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->value = value;
            moveToFront(node);
            return;
        }

        Node* node = new Node(key, value);
        addFront(node);
        mp[key] = node;

        if ((int)mp.size() > capacity) {
            Node* old = removeLeastRecent();
            if (old) {
                mp.erase(old->key);
                delete old;
            }
        }
    }

    void printState() {
        cout << "Cache state (MRU -> LRU): ";
        Node* cur = head->next;
        while (cur != tail) {
            cout << "(" << cur->key << ":" << cur->value << ") ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.printState();

    cache.put(2, 20);
    cache.printState();

    cout << "get(1) = " << cache.get(1) << "\n";
    cache.printState();

    cache.put(3, 30);
    cache.printState();

    cout << "get(2) = " << cache.get(2) << "\n";
    cache.printState();

    cache.put(4, 40);
    cache.printState();

    cout << "get(1) = " << cache.get(1) << "\n";
    cout << "get(3) = " << cache.get(3) << "\n";
    cout << "get(4) = " << cache.get(4) << "\n";

    cout << "\nTime complexity:\n";
    cout << "- get(): average O(1) using unordered_map + O(1) list updates\n";
    cout << "- put(): average O(1) for insert/update + O(1) eviction\n";

    return 0;
}
