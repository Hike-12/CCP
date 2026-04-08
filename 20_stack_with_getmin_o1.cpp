#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minS;

public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }

    int top() const {
        if (s.empty()) return -1;
        return s.top();
    }

    int getMin() const {
        if (minS.empty()) return -1;
        return minS.top();
    }

    bool empty() const {
        return s.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    cout << "Operations:\n";
    cout << "1 x -> push x\n";
    cout << "2   -> pop\n";
    cout << "3   -> top\n";
    cout << "4   -> getMin\n";

    MinStack ms;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            ms.push(x);
        } else if (type == 2) {
            ms.pop();
        } else if (type == 3) {
            if (ms.empty()) cout << "Stack is empty\n";
            else cout << "Top: " << ms.top() << "\n";
        } else if (type == 4) {
            if (ms.empty()) cout << "Stack is empty\n";
            else cout << "Min: " << ms.getMin() << "\n";
        }
    }

    return 0;
}
