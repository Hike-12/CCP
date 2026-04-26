// Sliding Window Maximum Using Deque (O(n))
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMax(const vector<int>& arr, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < (int)arr.size(); i++) {
        // Remove indices outside window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from back (they can never be maximum)
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Window has k elements
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nk=" << k << " Window max: ";
    auto res = slidingWindowMax(arr, k);
    for (int x : res) cout << x << " ";
    cout << "\n\n";

    arr = {2, 1, 5, 3, 6, 4, 8, 2};
    k = 4;
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nk=" << k << " Window max: ";
    res = slidingWindowMax(arr, k);
    for (int x : res) cout << x << " ";
    cout << "\n";
}
