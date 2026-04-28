#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMPAlgorithm {
private:
    string text;
    string pattern;
    vector<int> lps;
    
public:
    KMPAlgorithm(string t, string p) : text(t), pattern(p) {}
    
    // Build LPS (Longest Proper Prefix which is also Suffix) array
    void buildLPS() {
        cout << "\n=== Building LPS Array ===" << endl;
        int m = pattern.length();
        lps.assign(m, 0);
        
        int len = 0;
        int i = 1;
        
        cout << "Pattern: " << pattern << endl;
        cout << "Building process:\n";
        
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                cout << "  lps[" << i << "] = " << lps[i] << " (match found)" << endl;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                    cout << "  Backtrack to lps[" << len - 1 << "]" << endl;
                } else {
                    lps[i] = 0;
                    cout << "  lps[" << i << "] = 0 (no match)" << endl;
                    i++;
                }
            }
        }
        
        cout << "\nLPS Array: ";
        for (int x : lps) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    // Find all occurrences using KMP
    void findAllOccurrences() {
        cout << "\n=== Finding Occurrences ===" << endl;
        cout << "Text: " << text << endl;
        cout << "Pattern: " << pattern << endl;
        
        if (lps.empty()) {
            buildLPS();
        }
        
        int n = text.length();
        int m = pattern.length();
        vector<int> matches;
        
        int i = 0; // Text pointer
        int j = 0; // Pattern pointer
        
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            
            if (j == m) {
                matches.push_back(i - j);
                cout << "Match found at index: " << (i - j) << endl;
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        if (matches.empty()) {
            cout << "No matches found" << endl;
        } else {
            cout << "\nTotal Matches: " << matches.size() << endl;
            cout << "Match Indices: ";
            for (int idx : matches) {
                cout << idx << " ";
            }
            cout << endl;
        }
    }
    
    void printLPS() {
        if (lps.empty()) {
            buildLPS();
        }
        
        cout << "\nLPS Array Details:" << endl;
        cout << "Pattern: " << pattern << endl;
        cout << "LPS:     ";
        for (int i = 0; i < pattern.length(); i++) {
            cout << pattern[i] << " ";
        }
        cout << endl;
        cout << "Values:  ";
        for (int x : lps) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== KMP Pattern Matching Algorithm ===" << endl;
    
    // Test Case 1
    cout << "\n--- Test Case 1 ---" << endl;
    KMPAlgorithm kmp1("ABABDABACDABABCABAB", "ABABCABAB");
    kmp1.buildLPS();
    kmp1.findAllOccurrences();
    kmp1.printLPS();
    
    // Test Case 2
    cout << "\n\n--- Test Case 2 ---" << endl;
    KMPAlgorithm kmp2("AABAACAADAABAABA", "AABA");
    kmp2.buildLPS();
    kmp2.findAllOccurrences();
    kmp2.printLPS();
    
    // Test Case 3
    cout << "\n\n--- Test Case 3 ---" << endl;
    KMPAlgorithm kmp3("ABCCCCCCCCCCCCCCDDDFGH", "CCC");
    kmp3.buildLPS();
    kmp3.findAllOccurrences();
    kmp3.printLPS();
    
    return 0;
}
