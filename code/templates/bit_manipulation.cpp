


#include <bits/stdc++.h>
using namespace std;

// -------------------- BITWISE OPERATIONS --------------------

// 1. Bitwise AND / OR / XOR
void bitwise_ops(int a, int b) {
    cout << "AND: " << (a & b) << "\n";
    cout << "OR: " << (a | b) << "\n";
    cout << "XOR: " << (a ^ b) << "\n";
}

// 2. Left & Right shifting
void shift_ops(int a) {
    cout << "Left shift by 1: " << (a << 1) << "\n";
    cout << "Right shift by 1: " << (a >> 1) << "\n";
}
// 3. Checking if a bit is set
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

// 4. Setting / clearing / toggling a bit
int setBit(int n, int i) { return n | (1 << i); }
int clearBit(int n, int i) { return n & ~(1 << i); }
int toggleBit(int n, int i) { return n ^ (1 << i); }

// 5. Counting set bits (popcount)
int countSetBits(int n) { return __builtin_popcount(n); }

// 6. Checking power of two
bool isPowerOfTwo(int n) { return n > 0 && (n & (n-1)) == 0; }

// 7. Isolating lowest set bit (LSB)
int isolateLSB(int n) { return n & -n; }

// 8. Removing lowest set bit
int removeLSB(int n) { return n & (n-1); }

// 9. Bitmasking example: storing subsets
void printBitmask(int mask, int n) {
    for(int i=0;i<n;i++) cout << ((mask >> i) & 1);
    cout << "\n";
}

// 10. Subset generation using bitmasks
void generateSubsets(vector<int>& arr) {
    int n = arr.size();
    for(int mask=0; mask < (1 << n); mask++) {
        cout << "{ ";
        for(int i=0;i<n;i++) if(mask & (1 << i)) cout << arr[i] << " ";
        cout << "}\n";
    }
}

// 11. Swapping without temp variable
void swapWithoutTemp(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// 12. XOR tricks
// a) Find single number in array where every other appears twice
int findSingleNumber(vector<int>& arr) {
    int x = 0;
    for(int v: arr) x ^= v;
    return x;
}

// b) Find missing number 1..n in array of size n-1
int findMissingNumber(vector<int>& arr, int n) {
    int x1 = 0; // XOR of all numbers from 1..n
    for(int i=1;i<=n;i++) x1 ^= i;
    int x2 = 0; // XOR of array elements
    for(int v: arr) x2 ^= v;
    return x1 ^ x2;
}

// 13. Fast exponentiation using bits
long long fastExp(long long base, long long exp, long long mod=1e9+7) {
    long long res = 1;
    while(exp > 0) {
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
    ll res = 1;
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
    ll res = 1; 
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>=1 ;
    }

    ll res = 1;
    while(b) {
        if(b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
}

// 14. Using __builtin functions
void builtinExamples(int n) {
    cout << "Number of set bits: " << __builtin_popcount(n) << "\n";
    cout << "Leading zeros: " << __builtin_clz(n) << "\n";
    cout << "Trailing zeros: " << __builtin_ctz(n) << "\n";
    cout << "Parity (1 if odd number of set bits): " << __builtin_parity(n) << "\n";
}

int main() {
    // Examples
    int a = 6, b = 3;
    bitwise_ops(a,b);
    shift_ops(a);
    cout << "Bit 1 set? " << isBitSet(a,1) << "\n";
    cout << "Set bit 2: " << setBit(a,2) << "\n";
    cout << "Clear bit 1: " << clearBit(a,1) << "\n";
    cout << "Toggle bit 0: " << toggleBit(a,0) << "\n";
    cout << "Count set bits in " << a << ": " << countSetBits(a) << "\n";
    cout << "Is power of two? " << isPowerOfTwo(a) << "\n";
    cout << "Isolate LSB: " << isolateLSB(a) << "\n";
    cout << "Remove LSB: " << removeLSB(a) << "\n";

    vector<int> arr = {1,2,3};
    cout << "All subsets:\n";
    generateSubsets(arr);

    int x=5, y=7;
    swapWithoutTemp(x,y);
    cout << "Swap without temp: " << x << " " << y << "\n";

    vector<int> singleArr = {1,2,3,2,1};
    cout << "Single number: " << findSingleNumber(singleArr) << "\n";

    vector<int> missingArr = {1,2,4,5};
    cout << "Missing number: " << findMissingNumber(missingArr,5) << "\n";

    cout << "Fast exp 2^10: " << fastExp(2,10) << "\n";

    builtinExamples(a);

    return 0;
}
