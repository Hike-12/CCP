#include <iostream>
#include <cmath>
using namespace std;

class ModularArithmetic {
private:
    long long a, b, m;
    
public:
    ModularArithmetic(long long x, long long y, long long mod) : a(x), b(y), m(mod) {}
    
    // Compute GCD using Euclidean algorithm
    long long gcd(long long x, long long y) {
        cout << "\n--- Computing GCD(" << x << ", " << y << ") ---" << endl;
        
        while (y != 0) {
            long long temp = y;
            cout << "  gcd(" << x << ", " << y << ")" << endl;
            y = x % y;
            x = temp;
        }
        
        cout << "  GCD = " << x << endl;
        return x;
    }
    
    // Compute LCM using GCD
    long long lcm(long long x, long long y) {
        cout << "\n--- Computing LCM(" << x << ", " << y << ") ---" << endl;
        long long g = gcd(x, y);
        long long result = (x / g) * y; // Prevent overflow
        cout << "  LCM = (" << x << " / " << g << ") * " << y << " = " << result << endl;
        return result;
    }
    
    // Compute (a + b) mod m
    long long addMod() {
        cout << "\n--- Computing (" << a << " + " << b << ") mod " << m << " ---" << endl;
        long long result = (a + b) % m;
        cout << "  (" << a << " + " << b << ") % " << m << " = " << result << endl;
        return result;
    }
    
    // Compute (a * b) mod m
    long long multiplyMod() {
        cout << "\n--- Computing (" << a << " * " << b << ") mod " << m << " ---" << endl;
        long long result = (a * b) % m;
        cout << "  (" << a << " * " << b << ") % " << m << " = " << result << endl;
        return result;
    }
    
    // Check if numbers are coprime (GCD = 1)
    bool areCoprime(long long x, long long y) {
        cout << "\n--- Checking if " << x << " and " << y << " are Coprime ---" << endl;
        long long g = gcd(x, y);
        bool coprime = (g == 1);
        cout << "  GCD(" << x << ", " << y << ") = " << g << endl;
        cout << "  Coprime: " << (coprime ? "Yes" : "No") << endl;
        return coprime;
    }
};

int main() {
    cout << "=== Modular Arithmetic Operations ===" << endl;
    
    // Test Case 1
    cout << "\n=== Test Case 1: a=28, b=35, m=7 ===" << endl;
    ModularArithmetic ma1(28, 35, 7);
    
    ma1.gcd(28, 35);
    ma1.lcm(28, 35);
    ma1.addMod();
    ma1.multiplyMod();
    ma1.areCoprime(28, 35);
    
    // Test Case 2
    cout << "\n\n=== Test Case 2: a=17, b=19, m=5 ===" << endl;
    ModularArithmetic ma2(17, 19, 5);
    
    ma2.gcd(17, 19);
    ma2.lcm(17, 19);
    ma2.addMod();
    ma2.multiplyMod();
    ma2.areCoprime(17, 19);
    
    // Test Case 3
    cout << "\n\n=== Test Case 3: a=12, b=18, m=6 ===" << endl;
    ModularArithmetic ma3(12, 18, 6);
    
    ma3.gcd(12, 18);
    ma3.lcm(12, 18);
    ma3.addMod();
    ma3.multiplyMod();
    ma3.areCoprime(12, 18);
    
    // Test Case 4
    cout << "\n\n=== Test Case 4: a=25, b=36, m=11 ===" << endl;
    ModularArithmetic ma4(25, 36, 11);
    
    ma4.gcd(25, 36);
    ma4.lcm(25, 36);
    ma4.addMod();
    ma4.multiplyMod();
    ma4.areCoprime(25, 36);
    
    return 0;
}
