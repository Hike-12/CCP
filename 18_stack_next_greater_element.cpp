#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n), nge(n, -1);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (!st.empty()) nge[i] = st.top();
        st.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << "\n";
    }

    return 0;
}
