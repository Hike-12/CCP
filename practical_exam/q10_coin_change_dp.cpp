// Coin Change - Dynamic Programming (minimum coins)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChangeDP(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Reconstruct which coins were used
vector<int> coinsUsed(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    vector<int> last(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i && dp[i - coin] != INT_MAX && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                last[i] = coin;
            }
    vector<int> result;
    if (dp[amount] == INT_MAX) return {};
    for (int cur = amount; cur > 0; cur -= last[cur])
        result.push_back(last[cur]);
    return result;
}

int main() {
    vector<int> coins = {1, 5, 6, 9};
    int amount = 11;
    cout << "Coins: {1,5,6,9}, Amount: " << amount << "\n";
    cout << "Min coins: " << coinChangeDP(coins, amount) << "\n";
    auto used = coinsUsed(coins, amount);
    cout << "Coins used: "; for (int c : used) cout << c << " "; cout << "\n\n";

    coins = {2}; amount = 3;
    cout << "Coins: {2}, Amount: " << amount << "\n";
    cout << "Min coins: " << coinChangeDP(coins, amount) << " (impossible)\n\n";

    coins = {1, 3, 4}; amount = 6;
    cout << "Coins: {1,3,4}, Amount: " << amount << "\n";
    cout << "Min coins (DP): " << coinChangeDP(coins, amount) << "\n";
    used = coinsUsed(coins, amount);
    cout << "Coins used: "; for (int c : used) cout << c << " "; cout << "\n";
}
