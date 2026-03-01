// Pair With Given Sum in a Sorted Array (Two Pointers)
#include <iostream>
#include <vector>

using namespace std;

bool findPairWithSum(const vector<int>& arr, int target, int& a, int& b) {
    int i = 0;
    int j = (int)arr.size() - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            a = arr[i];
            b = arr[j];
            return true;
        }
        if (sum < target) i++;
        else j--;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 11, 15};
    int x = 15;

    int a = 0, b = 0;
    bool ok = findPairWithSum(arr, x, a, b);

    cout << "Sorted array: ";
    for (int v : arr) cout << v << " ";
    cout << "\nX: " << x << "\n";

    if (ok) cout << "Pair found (" << a << ", " << b << ")\n";
    else cout << "No pair found\n";

    cout << "Time Complexity: O(n)\n";

    return 0;
}
