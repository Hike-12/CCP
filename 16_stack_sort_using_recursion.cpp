#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertSorted(stack<int>& st, int x) {
    if (st.empty() || st.top() >= x) {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(topElement);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;

    int x = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, x);
}

void printStackTopToBottom(stack<int> st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;
    for (int x : arr) st.push(x);

    cout << "Original stack (top to bottom): ";
    printStackTopToBottom(st);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    printStackTopToBottom(st);

    return 0;
}
