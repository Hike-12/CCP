// First Repeating Element (Second Occurrence Appears First) - Brute Force vs Hashing
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstRepeatingBruteForce(const vector<int>& arr, long long& checks) {
    int n = (int)arr.size();
    checks = 0;

    int bestSecondIndex = n;
    int bestValue = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            checks++;
            if (arr[i] == arr[j]) {
                if (j < bestSecondIndex) {
                    bestSecondIndex = j;
                    bestValue = arr[i];
                }
                break;
            }
        }
    }

    return bestValue;
}

int firstRepeatingHashing(const vector<int>& arr, long long& checks) {
    int n = (int)arr.size();
    unordered_map<int, int> firstIndex;

    checks = 0;
    int bestSecondIndex = n;
    int bestValue = -1;

    for (int i = 0; i < n; i++) {
        checks++;
        auto it = firstIndex.find(arr[i]);
        if (it == firstIndex.end()) {
            firstIndex[arr[i]] = i;
        } else {
            if (i < bestSecondIndex) {
                bestSecondIndex = i;
                bestValue = arr[i];
            }
        }
    }

    return bestValue;
}

void runCase(const vector<int>& arr, const string& name) {
    cout << "\nCase: " << name << "\nArray: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    long long bruteChecks = 0;
    long long hashChecks = 0;

    int bruteAns = firstRepeatingBruteForce(arr, bruteChecks);
    int hashAns = firstRepeatingHashing(arr, hashChecks);

    cout << "Brute Force Answer: " << bruteAns << " | Checks: " << bruteChecks << " | Time: O(n^2)\n";
    cout << "Hashing Answer:     " << hashAns << " | Checks: " << hashChecks << " | Time: O(n) average\n";
}

int main() {
    vector<int> arr1 = {1, 2, 3, 2, 1};
    vector<int> arr2 = {5, 1, 2, 3, 4, 5};
    vector<int> arr3 = {10, 20, 30, 40, 50};

    runCase(arr1, "Repeat happens in middle");
    runCase(arr2, "Repeat happens late");
    runCase(arr3, "No repetition");

    cout << "\nComplexity comparison:\n";
    cout << "- Brute Force: O(n^2) comparisons in worst/average cases\n";
    cout << "- Hashing: O(n) average time, O(n) extra space (worst-case hashing can degrade)\n";

    return 0;
}
