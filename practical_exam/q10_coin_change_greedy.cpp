// Coin Change - Greedy Approach (works for canonical coin systems)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChangeGreedy(vector<int> coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    cout << "Coins used: ";
    for (int coin : coins) {
        while (amount >= coin) {
            cout << coin << " ";
            amount -= coin;
            count++;
        }
    }
    cout << "\n";
    if (amount != 0) { cout << "(Cannot make exact change with greedy)\n"; return -1; }
    return count;
}

int main() {
    // Standard denomination (greedy works)
    vector<int> coins = {1, 5, 10, 25};
    int amount = 41;
    cout << "Amount: " << amount << "\n";
    int c = coinChangeGreedy(coins, amount);
    cout << "Total coins: " << c << "\n\n";

    // Non-canonical (greedy may fail)
    coins = {1, 3, 4};
    amount = 6;
    cout << "Amount: " << amount << " | Coins: {1,3,4}\n";
    c = coinChangeGreedy(coins, amount);
    cout << "Greedy count: " << c << " (optimal is 2: 3+3)\n";
}
