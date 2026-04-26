// KMP (Knuth-Morris-Pratt) Pattern Searching
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildLPS(const string& pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;
    while (i < n) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    if (pat.empty()) return {};
    vector<int> lps = buildLPS(pat);
    vector<int> matches;
    int i = 0, j = 0;
    int n = text.size(), m = pat.size();
    while (i < n) {
        if (text[i] == pat[j]) { i++; j++; }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pat[j]) {
            j ? (j = lps[j - 1]) : i++;
        }
    }
    return matches;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pat  = "AABA";
    auto lps = buildLPS(pat);
    cout << "Pattern: " << pat << "\nLPS: ";
    for (int v : lps) cout << v << " ";
    cout << "\n";

    auto res = kmpSearch(text, pat);
    cout << "Text: " << text << "\n";
    cout << "Pattern found at indices: ";
    for (int i : res) cout << i << " ";
    cout << "\n\n";

    text = "AAAAABAAABA"; pat = "AAAA";
    res = kmpSearch(text, pat);
    cout << "Text: " << text << ", Pattern: " << pat << "\n";
    cout << "Found at: "; for (int i : res) cout << i << " "; cout << "\n";
}
