// Maximum Sum Subarray of Size K (Sliding Window - Fixed Window)
#include <iostream>
#include <vector>

using namespace std;

int maxSumSubarraySizeK(const vector<int>& arr, int k) {
    if (k <= 0 || k > (int)arr.size()) return 0;

    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];

    long long best = windowSum;

    for (int i = k; i < (int)arr.size(); i++) {
        windowSum -= arr[i - k];
        windowSum += arr[i];
        if (windowSum > best) best = windowSum;
    }

    return (int)best;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int ans = maxSumSubarraySizeK(arr, k);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nK: " << k << "\n";
    cout << "Maximum sum of any subarray of size K: " << ans << "\n";
    cout << "Time Complexity: O(n)\n";

    return 0;
}
