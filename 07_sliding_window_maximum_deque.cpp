// Sliding Window Maximum (Deque) - O(n)
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < (int)arr.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);

        if (i >= k - 1) ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = maxSlidingWindow(arr, k);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nK: " << k << "\n";

    cout << "Sliding window maximums: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    cout << "Time Complexity: O(n)\n";

    return 0;
}
