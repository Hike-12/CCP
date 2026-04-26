// Sort a Stack Using Recursion
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int val) {
    if (st.empty() || st.top() <= val) {
        st.push(val);
        return;
    }
    int top = st.top(); st.pop();
    insertSorted(st, val);
    st.push(top);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;
    int top = st.top(); st.pop();
    sortStack(st);
    insertSorted(st, top);
}

void printStack(stack<int> st) {
    cout << "Top -> ";
    while (!st.empty()) { cout << st.top() << " "; st.pop(); }
    cout << "\n";
}

int main() {
    stack<int> st;
    for (int v : {3, 1, 4, 2, 5}) st.push(v);
    cout << "Before: "; printStack(st);
    sortStack(st);
    cout << "After:  "; printStack(st);

    stack<int> st2;
    for (int v : {-2, 9, 0, -5, 3}) st2.push(v);
    cout << "Before: "; printStack(st2);
    sortStack(st2);
    cout << "After:  "; printStack(st2);
}
