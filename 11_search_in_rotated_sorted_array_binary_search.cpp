// Search in Rotated Sorted Array (Modified Binary Search)
#include <iostream>
#include <vector>

using namespace std;

int searchRotated(const vector<int>& arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (arr[mid] < target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int idx = searchRotated(arr, target);

    cout << "Array: ";
    for (int v : arr) cout << v << " ";
    cout << "\nTarget: " << target << "\n";

    cout << "Index: " << idx << "\n";
    cout << "Time Complexity: O(log n)\n";

    return 0;
}
