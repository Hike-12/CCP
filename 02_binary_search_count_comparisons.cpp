// Binary Search (Count Comparisons)
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int key, long long& comparisons) {
    int low = 0;
    int high = (int)arr.size() - 1;
    comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if (arr[mid] == key) return mid;

        comparisons++;
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 7, 9, 12, 18, 21, 30, 44};
    int key = 18;

    long long comparisons = 0;
    int idx = binarySearch(arr, key, comparisons);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nKey: " << key << "\n";

    cout << "Result index: " << idx << "\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Complexity: Best O(1), Average O(log n), Worst O(log n)\n";

    return 0;
}
