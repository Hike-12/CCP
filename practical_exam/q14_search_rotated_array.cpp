// Search in Rotated Sorted Array (Modified Binary Search)
#include <iostream>
#include <vector>
using namespace std;

int searchRotated(const vector<int>& arr, int target) {
    int low = 0, high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else { // Right half is sorted
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    for (int t : {0, 3, 6, 7}) {
        int idx = searchRotated(arr, t);
        cout << "Search " << t << " -> index " << idx;
        if (idx == -1) cout << " (not found)";
        cout << "\n";
    }

    arr = {1};
    cout << "Search 0 in {1} -> " << searchRotated(arr, 0) << "\n";
    cout << "Search 1 in {1} -> " << searchRotated(arr, 1) << "\n";
}
