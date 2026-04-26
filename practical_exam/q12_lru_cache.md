### Problem: LRU Cache (Doubly Linked List + HashMap)

---

### Short Revision Notes (Exam Quick Recall)

- Pattern: DLL + HashMap for O(1) get and put
- Core Idea: DLL maintains access order (MRU at front, LRU at back); HashMap gives O(1) node lookup
- Key Trick: Use dummy head and tail nodes to simplify insert/remove edge cases
- Complexity: O(1) get and put

---

### Code Snippet (Important Part Only)

```cpp
int get(int key) {
    if (!cache.count(key)) return -1;
    remove(cache[key]);
    insertFront(cache[key]);   // mark as recently used
    return cache[key]->val;
}

void put(int key, int val) {
    if (cache.count(key)) { /* update + move to front */ }
    else {
        if (cache.size() == capacity) {
            Node* lru = tail->prev;  // least recently used
            remove(lru); cache.erase(lru->key); delete lru;
        }
        Node* node = new Node(key, val);
        cache[key] = node; insertFront(node);
    }
}
```

---

### Detailed Explanation

- **HashMap:** `key → Node*` for O(1) access to any node.
- **DLL:** Maintains recency order. Front (after dummy head) = most recently used. Back (before dummy tail) = least recently used.
- **get:** If key exists, move its node to front (mark MRU), return value.
- **put:** If key exists, update and move to front. If new and full, evict LRU (tail->prev), then insert new node at front.
- **Dummy nodes:** Eliminate special cases for inserting/removing at ends.

**Edge cases:**
- Accessing an existing key: must move to front
- Capacity 1: every new insert evicts the previous
- Updating existing key: counts as access

**Common mistakes:**
- Not moving node to front on `get` (wrong recency tracking)
- Memory leak: not deleting evicted node
- Not erasing from HashMap when evicting

---

### Dry Run

Capacity=3, operations: put(1,10), put(2,20), put(3,30), get(1), put(4,40)

```
After put(1,10): [1]
After put(2,20): [2,1]
After put(3,30): [3,2,1]
get(1)=10:       [1,3,2]   ← 1 moved to front
put(4,40):       evict LRU=2, [4,1,3]
get(2) = -1      ← evicted
```

---

### Visualization (USE MERMAID ONLY, NO ASCII)

```mermaid
graph LR
    H[HEAD] <--> N1["key=1"] <--> N3["key=3"] <--> N2["key=2"] <--> T[TAIL]
    style H fill:#ddd
    style T fill:#ddd
    style N2 fill:#f96,stroke:#333
```
