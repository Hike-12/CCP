// Longest Substring Without Repeating Characters (Sliding Window + HashMap)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> last;
    int left = 0, maxLen = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        if (last.count(s[right]) && last[s[right]] >= left)
            left = last[s[right]] + 1;
        last[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// Also returns the actual substring
string longestSubstring(const string& s) {
    unordered_map<char, int> last;
    int left = 0, maxLen = 0, start = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        if (last.count(s[right]) && last[s[right]] >= left)
            left = last[s[right]] + 1;
        last[s[right]] = right;
        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            start = left;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    for (const string& s : {"abcabcbb", "bbbbb", "pwwkew", "dvdf"}) {
        cout << "Input: \"" << s << "\" -> Length: " << lengthOfLongestSubstring(s)
             << ", Substring: \"" << longestSubstring(s) << "\"\n";
    }
}
