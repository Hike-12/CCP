// Next Greater Element Using Stack (O(n))
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25, 7};
    auto res = nextGreaterElement(arr);
    cout << "Array:  ";
    for (int x : arr) cout << x << " ";
    cout << "\nNGE:    ";
    for (int x : res) cout << x << " ";
    cout << "\n\n";

    arr = {13, 7, 6, 12};
    res = nextGreaterElement(arr);
    cout << "Array:  ";
    for (int x : arr) cout << x << " ";
    cout << "\nNGE:    ";
    for (int x : res) cout << x << " ";
    cout << "\n";
}
