#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter N: ";
    cin >> n;

    queue<string> q;
    q.push("1");

    cout << "Binary numbers from 1 to " << n << ":\n";
    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr;
        if (i < n) cout << " ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << "\n";

    return 0;
}
