#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    priority_queue<int> maxHeap;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxHeap.push(x);
    }

    cout << "Elements in priority order (max-heap): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top();
        maxHeap.pop();
        if (!maxHeap.empty()) cout << " ";
    }
    cout << "\n";

    return 0;
}
