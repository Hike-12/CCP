#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class CoinChange {
private:
    vector<int> coins;
    int amount;
    
public:
    CoinChange(vector<int> c, int a) : coins(c), amount(a) {}
    
    // Greedy approach - pick largest denomination first
    int greedyApproach() {
        cout << "\n=== Greedy Approach ===" << endl;
        vector<int> sortedCoins = coins;
        sort(sortedCoins.rbegin(), sortedCoins.rend()); // Descending order
        
        int count = 0;
        int remaining = amount;
        
        cout << "Coins (descending): ";
        for (int c : sortedCoins) cout << c << " ";
        cout << "\nAmount: " << amount << endl;
        
        cout << "Picking coins: ";
        for (int coin : sortedCoins) {
            while (remaining >= coin) {
                cout << coin << " ";
                remaining -= coin;
                count++;
            }
        }
        cout << "\nCoins needed: " << count << endl;
        
        return count;
    }
    
    // Dynamic Programming approach - compute true minimum
    int dpApproach() {
        cout << "\n=== Dynamic Programming Approach ===" << endl;
        vector<int> dp(amount + 1, INT_MAX);
        vector<int> parent(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    if (dp[i - coin] + 1 < dp[i]) {
                        dp[i] = dp[i - coin] + 1;
                        parent[i] = coin;
                    }
                }
            }
        }
        
        cout << "DP array: ";
        for (int i = 0; i <= min(amount, 10); i++) {
            if (dp[i] == INT_MAX) cout << "INF ";
            else cout << dp[i] << " ";
        }
        cout << "...\n";
        
        cout << "Coins used: ";
        int curr = amount;
        while (curr > 0) {
            int coin = parent[curr];
            cout << coin << " ";
            curr -= coin;
        }
        cout << "\nCoins needed: " << dp[amount] << endl;
        
        return dp[amount];
    }
    
    void compare() {
        int greedy = greedyApproach();
        int dp = dpApproach();
        
        cout << "\n=== Comparison ===" << endl;
        cout << "Greedy coins: " << greedy << endl;
        cout << "DP coins: " << dp << endl;
        
        if (greedy == dp) {
            cout << "Result: Greedy is Optimal" << endl;
        } else {
            cout << "Result: Not Optimal" << endl;
            cout << "Greedy approach uses " << (greedy - dp) << " more coins than optimal" << endl;
        }
    }
};

int main() {
    cout << "=== Coin Change: Greedy vs DP ===" << endl;
    
    // Test Case 1: Greedy is optimal
    cout << "\n--- Test Case 1: {1, 5, 10, 25} ---" << endl;
    vector<int> coins1 = {1, 5, 10, 25};
    int amount1 = 41;
    CoinChange cc1(coins1, amount1);
    cc1.compare();
    
    // Test Case 2: Greedy is NOT optimal
    cout << "\n\n--- Test Case 2: {1, 3, 4} ---" << endl;
    vector<int> coins2 = {1, 3, 4};
    int amount2 = 6;
    CoinChange cc2(coins2, amount2);
    cc2.compare();
    
    // Test Case 3: Another non-optimal case
    cout << "\n\n--- Test Case 3: {1, 5, 10, 21, 25} ---" << endl;
    vector<int> coins3 = {1, 5, 10, 21, 25};
    int amount3 = 63;
    CoinChange cc3(coins3, amount3);
    cc3.compare();
    
    return 0;
}
