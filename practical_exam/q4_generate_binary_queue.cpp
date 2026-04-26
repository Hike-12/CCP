// Generate Binary Numbers from 1 to N Using Queue
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        string curr = q.front(); q.pop();
        cout << curr << "\n";
        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    cout << "Binary numbers 1 to 10:\n";
    generateBinary(10);

    cout << "\nBinary numbers 1 to 5:\n";
    generateBinary(5);
}
