// Linear Search (Count Comparisons)
#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& arr, int key, long long& comparisons) {
    comparisons = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {12, 5, 9, 21, 7, 18, 3};
    int key = 7;

    long long comparisons = 0;
    int idx = linearSearch(arr, key, comparisons);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nKey: " << key << "\n";

    cout << "Result index: " << idx << "\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Time Complexity: Best O(1), Average O(n), Worst O(n)\n";

    return 0;
}
