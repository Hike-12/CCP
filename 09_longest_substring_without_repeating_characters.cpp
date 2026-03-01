// Longest Substring Without Repeating Characters (Sliding Window + Hashing)
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> last;

    int left = 0;
    int best = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        auto it = last.find(s[right]);
        if (it != last.end() && it->second >= left) {
            left = it->second + 1;
        }
        last[s[right]] = right;

        int len = right - left + 1;
        if (len > best) best = len;
    }

    return best;
}

int main() {
    string s = "abcabcbb";

    int ans = lengthOfLongestSubstring(s);

    cout << "String: " << s << "\n";
    cout << "Longest substring length (no repeating chars): " << ans << "\n";
    cout << "Time Complexity: O(n) average\n";

    return 0;
}
