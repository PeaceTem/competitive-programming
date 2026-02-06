## Multiset and Prefix Sum (CF)
- **`multiset::count(x)` can degrade** when there are many duplicates, since it may scan all occurrences.  
    Prefer `find(x)` + `erase(iterator)` to remove **only one occurrence** in `O(log n)`.
    
- **`multiset::erase(value)` removes all occurrences** of that value, which is often unintended and can break invariants.  
    Use `erase(it)` when you want to delete a single element.
    
- **Prefix sums help maintain balance in sliding windows** by allowing constant-time removal of window contributions instead of recomputing sums, preventing performance degradation.
## Longest Increasing Subsequence O(nlgn)

```
vector<int> a = {2, 3, 1, 5, 6, 6, 5};
vector<int> k;

for(int i = 0; i < n; i++){
	auto it = lower_bound(k.begin(), k.end(), a[i]);
	
	if(it == k.end()){
		k.push_back(a[i]);
	} else *it = a[i];
}

cout << k.size() << endl;
```


## i mod k
for a block of integers at index [l, r], one can set the element at each index to be index % k.
The result segment will be [0, 1, ..., k]. 
Note that this segment may be shifted -> [1, 2, ..., k, 0]

But it's guaranteed that the elements are going to be i < k

### `lower_bound` / `upper_bound` on ordered containers (C++)

For **ordered associative containers** (`set`, `multiset`, `map`, `multimap`), **always use the container’s member functions**, not `std::lower_bound`.
```
it = container.lower_bound(x);  // first element >= x
it = container.upper_bound(x);  // first element > x
```
- Works in **O(log n)** (tree-based).
    
- Using `std::lower_bound(begin, end, x)` on these containers is **O(n)** ❌.
    

**Containers & meaning**

- `set`, `multiset`: compare by **value**
    
- `map`, `multimap`: compare by **key**
    

**Notes**

- `multiset` / `multimap` allow duplicates  
    → range of equals: `[lower_bound(x), upper_bound(x))`
    
- `unordered_*` containers **do not support** these operations.
## 🔹 2D Prefix Sum

**Idea:**  
`ps[i][j]` = sum of submatrix `(0,0) → (i-1,j-1)`

**Build**
```
ps[i][j] = a[i-1][j-1] 
         + ps[i-1][j] + ps[i][j-1] 
         - ps[i-1][j-1];

```
**Query sum of (r1,c1) → (r2,c2)** (1-based ps)
```
sum = ps[r2][c2] - ps[r1-1][c2] - ps[r2][c1-1] + ps[r1-1][c1-1];
```
**Use when:** many rectangle sum queries  
**Time:** build `O(nm)`, query `O(1)`

## 🔹 Prefix XOR

**Idea:**  
`px[i]` = `a[0] ^ a[1] ^ ... ^ a[i-1]`

**Build**
```
px[0] = 0;
px[i+1] = px[i] ^ a[i];
```
Query XOR of [l, r]
```
xor_lr = px[r+1] ^ px[l];
```
**Key property:** `x ^ x = 0`  
**Use when:** XOR range queries, subarray XOR tricks

## 🔹 Kadane’s Algorithm

**Idea:**  
Best subarray ending here vs start new
```
cur = max(a[i], cur + a[i]);
ans = max(ans, cur);
```
Full
```
int cur = a[0], ans = a[0];
for (int i = 1; i < n; i++) {
    cur = max(a[i], cur + a[i]);
    ans = max(ans, cur);
}
```
**Finds:** maximum subarray sum  
**Time:** `O(n)`  
**Works with negatives**

### Monotonic Stack
**Monotonic Stack Trick:**  
Maintain a stack in increasing or decreasing order to find previous/next smaller or greater elements in `O(n)`.  
Each element is pushed and popped at most once.

Common uses: histogram rectangles, subarray min/max contribution, boundary detection.

**Pattern (next smaller element):**
```
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i])
        st.pop();
    left[i] = st.empty() ? -1 : st.top();
    st.push(i);
}
```
When an element is popped, the current index forms its boundary.

### Prefix Xor
**Prefix XOR Trick:**  
Define prefix XOR:  
`px[0] = 0`  
`px[i] = a[0] ^ a[1] ^ ... ^ a[i-1]`

Any subarray XOR can be computed as:  
`XOR(l, r) = px[r+1] ^ px[l]`

Therefore, subarray XOR constraints translate into constraints on prefix XOR values.  
For construction problems, design the prefix XOR array first, then derive the array using:  
`a[i] = px[i] ^ px[i-1]`.