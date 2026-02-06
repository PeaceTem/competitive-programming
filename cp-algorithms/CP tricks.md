# Bit Manipulation

### Clear bit
```
x &= ~(1 << k); x &= ~(1 << k);
```
### Toggle bit
```
x ^= (1 << k); x ^= (1 << k);
```
### Counting Set Bits
```
int count = 0;
while (x) {
    x &= (x - 1); // remove lowest set bit
    count++;
}
// remove lsb
x = x & (x - 1);
__builtin_popcount(x);
// Built-in
__builtin_popcount(x);            // 32-bit
__builtin_popcountll(x);         // 64-bit

```

### Checking if a number is power of 2
```
bool isPowerOfTwo(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
}

x > 0 && (x & (x - 1)) == 0;
```
### Lowest Set Bit
```
int lsb = x & -x;
// 1100 & 0100 = 0100 (4)

int lsb = x & -x;
```
### Removing Lowest Set Bit
```
x &= (x - 1);
```
### Remove element in Bitmask
```
mask &= ~(1<<i)
```
### Swap without a temp variable
```
a ^= b;
b ^= a;
a ^= b;
```

## XOR Tricks
### Missing Number
Single Number
```
int ans = 0;
for (int x : nums) ans ^= x;
return ans;
```

Missing Number
```
int ans = n;
for(int i = 0; i < n; i++)
    ans ^= i ^ nums[i];
return ans;
```
### Useful GCC Built-in

```
__builtin_popcount(x);
__builtin_popcountll(x);

__builtin_ctz(x);   // count trailing zeros
__builtin_clz(x);   // count leading zeros

__builtin_parity(x); // 1 if odd number of 1 bits

```

# ⭐ VERY IMPORTANT XOR THEOREMS (You MUST know these)

### **Property 1: x ^ x = 0**

Identical values cancel out.

### **Property 2: x ^ 0 = x**

XOR with 0 changes nothing.

### **Property 3: XOR is commutative**

`a ^ b = b ^ a`

### **Property 4: XOR is associative**

`a ^ (b ^ c) = (a ^ b) ^ c`

### **Property 5: XOR can swap two numbers**

`a ^= b b ^= a a ^= b`

### **Property 6: XOR finds the unique element**

If all numbers appear twice except one:

`a ⊕ a ⊕ b ⊕ c ⊕ c = b`

➡️ Used in LeetCode “Single Number”.

### (1) XOR = OR – AND
```
a ^ b = (a | b) & ~(a & b)
```
### XOR + AND/OR to Detect Bit Transitions
#### Bit changed from 0 → 1
```
new = a ^ b;
added_bits = new & b;
```
#### Bit changed from 1 → 0
```
removed_bits = new & a;
```

### Isolate the highest set bit
```
1 << (31 - __builtin_clz(x));
```

### When iterating subset of a mask
```
for (int s = mask; s; s = (s - 1) & mask) {}
```
### XOR + AND to Compute Carry in Addition
```
sum  = a ^ b          // XOR gives sum without carry
carry = (a & b) << 1  // AND detects carry bits
```
### Mask out bits between L and R
```
mask = ((1 << (r - l + 1)) - 1) << l;
x &= ~mask;   // clear bits
x ^= mask;    // toggle bits
x |= mask;    // set bits
```
# Add x + y - 2(x & y)


# 🌟 **What Is Bitmasking?**

Bitmasking = using the bits of an integer to represent **choices**, **states**, or **subsets**.

Each bit is either:

- `0` → **not selected**
    
- `1` → **selected**
    

So one integer can represent a **whole set of decisions**.
bit:   3 2 1 0
word: good dad cat dog
mask: 1010 -> choose 3 and 1 (choose the set bits)
bit 3 = 0 → good   NOT chosen
bit 2 = 1 → dad    chosen
bit 1 = 0 → cat    NOT chosen
bit 0 = 1 → dog    chosen

- ?
    

---

# 💡 How Do We Loop Through All Subsets?

If you have `n` words:

`total subsets = 2^n`

So we loop:

`for (int mask = 0; mask < (1 << n); mask++) {     // mask represents one subset }`

Example: n = 3 → subsets:

`mask = 0 → 000 → {} mask = 1 → 001 → {0} mask = 2 → 010 → {1} mask = 3 → 011 → {1,0} mask = 4 → 100 → {2} mask = 5 → 101 → {2,0} mask = 6 → 110 → {2,1} mask = 7 → 111 → {2,1,0}`

This enumerates **every possible combination**.

#### To chose a particular element at index i
for (int i = 0; i < n; i++) {
	if (mask & (1 << i)) { // this picks the element at index i;

backtracking: 
  

        for(int c = 0; c < k; c++) {

            load[c] += cookies[i];

  

            if(load[c] < ans) dfs(i+1, cookies, load, k);

  

            load[c] -= cookies[i];

  

            if(load[c] == 0) break;

        }

    }

# Unique Paths
# ✅ **BEST SOLUTION — Combinatorics (No DP Needed!)**

To go from top-left to bottom-right in an **m × n** grid, the robot must make:

- **(m − 1)** down moves
    
- **(n − 1)** right moves
    

Total moves = **(m+n−2)**  
Choose positions for either the down moves or right moves.

So the number of unique paths is:

(m+n−2m−1)=(m+n−2)!(m−1)!(n−1)!\binom{m+n-2}{m-1} = \frac{(m+n-2)!}{(m-1)!(n-1)!}(m−1m+n−2​)=(m−1)!(n−1)!(m+n−2)!​

Compute this safely without overflow using multiplication.

### ✅ Clean Optimized C++ Code (Best)

`class Solution { 
	public:     
		int uniquePaths(int m, int n) {         
			long long res = 1;         
			int k = min(m - 1, n - 1);         
			int total = m + n - 2;          
			for (int i = 1; i <= k; i++) {             
				res = res * (total - k + i) / i;         
			}         
			
			return res;     
			
		} 
	};`

### 🔥 Why this is the best:

- **O(1) space**
    
- **O(min(m, n)) time**
    
- No DP table
    
- No recursion
    
- No overflow (within constraints)

# ✅ Second-Best — DP (Bottom-Up)

If you want a dynamic programming version:
```class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
	    }
};
```

Space: O(mn)  
Time: O(mn)

# Most Memory Efficient DP (1D)

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
```
Space: O(n)  
Time: O(mn)


# 🔥 1. What is Modular Inverse?
# ✔ Method 1 — Using Fermat’s Little Theorem (MOST COMMON)

**Use this when m is PRIME.**

This is the case when m = 1,000,000,007 (CP standard).

Fermat’s Little Theorem says:
```
long long modpow(long long a, long long b, long long m) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return r;
}

long long modinv(long long a, long long m) {
    return modpow(a, m - 2, m);
}
```

# ✔ Method 3 — Precompute all inverses from 1 … n

Useful when you need many inverses.

Formula:

inv[i]=m−(m/i)⋅inv[m%i]mod m

Runs in O(n).

```
vector<long long> computeInverses(int n, long long m) {
    vector<int> inv(n+1);
    inv[1] = 1;
    
    for(int i=2; i<=n; i++){
	    inv[i] = m - (m / i) * inv[m % i] % m;
    }
    
    return inv;
}
```

# ✅ **C++ Implementation (Factorials + Inverse Factorials + Inverses)**

```
const int MOD = 1e9 + 7;
const int MAXN = 2000000; // choose limit you need

long long fact[MAXN + 1];
long long inv[MAXN + 1];
long long invfact[MAXN + 1];

void precompute() {
    // 1. modular inverses (O(n))
    inv[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    // 2. factorials (O(n))
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // 3. inverse factorials (O(n))
    invfact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        invfact[i] = invfact[i - 1] * inv[i] % MOD;
    }
    
}

```

# ✅ **How to compute nCk using factorials**

```
long long nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

```

# Sum of all pairwise product
(total_sum² - sum_of_squares) / 2

# LCS Iterative DP
```
int longestCommonSubsequence(string text1, string text2) {

	int n = text1.length();
	int m = text2.length();

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(text1[i-1] == text2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
```

# LIS
```
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);

        for(int i=0; i < n; i++){
	        for(int j=0; j < i; j++){
		        if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
	        }
	    }
        return *max_element(dp.begin(), dp.end());
    }
```

# Binary Search on Answer Space
```
bool check(int mid, vector<int>& weights, int days){
        int cnt = 1;
        int acc = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] > mid) return false;
            acc += weights[i];
            if(acc > mid){
                cnt++;
                acc = weights[i];
            }
        }
        return cnt <= days;
    }
```

# Search in a rotated array

```
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } 
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
}

```


# Disjoint Set Union / Union Find

```
vector<int> parent, size;

int find(int x){
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a != b){
		if(size[a] < size[b]) swap(a, b);
		
		parent[b] = a;
		size[a] += size[b];
	}
}

void performOperation(){
	int n; cin>>n;
	parent.resize(n);
	size.resize(n, 1);
	iota(parent.begin(), parent.end(), 0);
	
	// perform the union and find operation.
}
```

# 🧠 **General Template (Non-Decreasing Subsequences)**

```
vector<long long> dp(K+1, 0);

for (int x : a) {
    long long extend = 0;
    for (int i = 1; i <= x; i++)
        extend = (extend + dp[i]) % MOD;

    // duplicate handling
    dp[x] = (dp[x] * 2) % MOD;

    // extend OR start new
    dp[x] = (dp[x] + extend + 1) % MOD;
}

```

## 🏁 **If the question gives values only {1,2,3}, you can optimize:**

```
if (x == 1) {
    dp[1] = (dp[1]*2 + 1) % MOD;
}
if (x == 2) {
    dp[2] = (dp[2]*2 + dp[1] + 1) % MOD;
}
if (x == 3) {
    dp[3] = (dp[3]*2 + dp[1] + dp[2] + 1) % MOD;
}

```
