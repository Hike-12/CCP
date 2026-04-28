#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class BitwiseOperations {
public:
    
    // Print binary representation
    void printBinary(long long num) {
        cout << "Binary: ";
        if (num == 0) {
            cout << "0" << endl;
            return;
        }
        
        vector<int> binary;
        long long temp = num;
        while (temp > 0) {
            binary.push_back(temp % 2);
            temp /= 2;
        }
        
        for (int i = binary.size() - 1; i >= 0; i--) {
            cout << binary[i];
        }
        cout << endl;
    }
    
    // Reverse bits using bitwise operations
    long long reverseBits(long long num) {
        cout << "\n--- Reversing Bits ---" << endl;
        printBinary(num);
        
        long long reversed = 0;
        long long temp = num;
        
        while (temp > 0) {
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }
        
        cout << "Reversed Binary: ";
        printBinary(reversed);
        cout << "Decimal Value: " << reversed << endl;
        
        return reversed;
    }
    
    // Count set bits (1s in binary)
    int countSetBits(long long num) {
        cout << "\n--- Counting Set Bits ---" << endl;
        printBinary(num);
        
        int count = 0;
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
        
        cout << "Set Bits Count: " << count << endl;
        return count;
    }
    
    // XOR trick demonstration
    void xorTrick() {
        cout << "\n--- XOR Trick: Finding Unpaired Element ---" << endl;
        vector<int> arr = {1, 2, 3, 2, 3, 1, 4};
        
        cout << "Array: ";
        for (int x : arr) cout << x << " ";
        cout << endl;
        
        cout << "Explanation: All paired elements cancel out in XOR" << endl;
        cout << "Because: a XOR a = 0, a XOR 0 = a\n" << endl;
        
        int result = 0;
        cout << "XOR Operations:" << endl;
        for (int x : arr) {
            result ^= x;
            cout << "  Result XOR " << x << " = " << result << endl;
        }
        
        cout << "\nUnpaired Element: " << result << endl;
    }
    
    // Generate all subsets using bit masking
    void generateSubsets() {
        cout << "\n--- Generate All Subsets using Bit Masking ---" << endl;
        vector<int> set = {1, 2, 3};
        int n = set.size();
        int totalSubsets = (1 << n);
        
        cout << "Set: ";
        for (int x : set) cout << x << " ";
        cout << endl;
        cout << "Total subsets: " << totalSubsets << "\n" << endl;
        
        for (int i = 0; i < totalSubsets; i++) {
            cout << "Subset " << i << " (binary: " << bitset<3>(i) << "): { ";
            for (int j = 0; j < n; j++) {
                // Check if j-th bit is set in i
                if (i & (1 << j)) {
                    cout << set[j] << " ";
                }
            }
            cout << "}\n";
        }
    }
};

int main() {
    BitwiseOperations bio;
    
    cout << "=== Bitwise Operations ===" << endl;
    
    long long num = 29;
    cout << "\nInput Number: " << num << endl;
    bio.printBinary(num);
    
    long long reversed = bio.reverseBits(num);
    
    bio.countSetBits(num);
    
    bio.xorTrick();
    
    bio.generateSubsets();
    
    return 0;
}
