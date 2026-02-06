//---------------------------  
// Segment Tree Template for Range Sum Query and Point Update
// Usage:
// 1. Initialize NumArray with the input array.
// 2. Use update(index, val) to update the value at index.
// 3. Use sumRange(left, right) to get the sum in the range [left, right].
//---------------------------

class NumArray {
public:
    int n; vector<int> tree;
    NumArray(vector<int>& a){
        n = a.size();
        tree.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r){
            tree[node] = a[l]; return;
        }

        int mid = l + (r - l) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int index, int val) {
        if(n == 0) return;
        update(1, 0, n - 1, index, val);
    }
    
    void update(int node, int l, int r, int idx, int val){
        if(l == r) {
            tree[node] = val; return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    
    int sumRange(int left, int right) {
        if(n == 0) return 0;
        return query(1, 0, n - 1, left, right);
    }
    
    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];

        int mid = l + (r - l) / 2;

        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};


// Range Minimum Query Segment Tree Template
class NumArrayMin {
public:
    int n;
    vector<int> tree;

    NumArrayMin(vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, INT_MAX);
        if(n > 0) build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int index, int val) {
        if(n == 0) return;
        update(1, 0, n - 1, index, val);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int minRange(int left, int right) {
        if(n == 0) return INT_MAX;
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return INT_MAX; // outside query
        if(ql <= l && r <= qr) return tree[node]; // fully inside

        int mid = l + (r - l) / 2;
        return min(query(node * 2, l, mid, ql, qr),
                   query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};



// Range GCD queries

#include <bits/stdc++.h>
using namespace std;

class NumArrayGCD {
public:
    int n;
    vector<int> tree;

    NumArrayGCD(vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        if(n > 0) build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int index, int val) {
        if(n == 0) return;
        update(1, 0, n - 1, index, val);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
    }

    int gcdRange(int left, int right) {
        if(n == 0) return 0;
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0; // gcd(x,0)=x
        if(ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        return gcd(query(node * 2, l, mid, ql, qr),
                   query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};


// Range Xor Queries

#include <bits/stdc++.h>
using namespace std;

class NumArrayXOR {
public:
    int n;
    vector<int> tree;

    NumArrayXOR(vector<int>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        if(n > 0) build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }

    void update(int index, int val) {
        if(n == 0) return;
        update(1, 0, n - 1, index, val);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) update(node * 2, l, mid, idx, val);
        else update(node * 2 + 1, mid + 1, r, idx, val);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }

    int xorRange(int left, int right) {
        if(n == 0) return 0;
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;  // identity for XOR
        if(ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};



// ✅ 1. Segment Tree With Lazy Propagation (Range Add + Range Sum Query)

struct SegTreeSum {
    int n;
    vector<long long> tree, lazy;

    SegTreeSum(int n) : n(n) {
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void build(vector<long long> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a, node*2, l, mid);
        build(a, node*2+1, mid+1, r);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    void push(int node, int l, int r) {
        if(lazy[node] != 0) {
            long long val = lazy[node];
            tree[node] += val * (r - l + 1);

            if(l != r) {
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);

        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if(r < ql || l > qr) return 0;

        if(ql <= l && r <= qr) return tree[node];

        int mid = (l+r)/2;
        return query(node*2, l, mid, ql, qr)
             + query(node*2+1, mid+1, r, ql, qr);
    }
};



// ✅ 2. Segment Tree With Lazy Propagation (Range Update + Range Min Query)
struct SegTreeMin {
    int n;
    vector<long long> tree, lazy;

    SegTreeMin(int n) : n(n) {
        tree.assign(4*n, 1e18);
        lazy.assign(4*n, 0);
    }

    void build(vector<long long> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a, node*2, l, mid);
        build(a, node*2+1, mid+1, r);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    void push(int node, int l, int r) {
        if(lazy[node] != 0) {
            tree[node] += lazy[node];

            if(l != r) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);

        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if(r < ql || l > qr) return 1e18;

        if(ql <= l && r <= qr) return tree[node];

        int mid = (l+r)/2;
        return min(query(node*2, l, mid, ql, qr),
                   query(node*2+1, mid+1, r, ql, qr));
    }
};

// ✅ 3. Segment Tree With Lazy Propagation (Range Update + Range Max Query)

struct SegTreeMax {
    int n;
    vector<long long> tree, lazy;

    SegTreeMax(int n) : n(n) {
        tree.assign(4*n, -1e18);
        lazy.assign(4*n, 0);
    }

    void build(vector<long long> &a, int node, int l, int r) {
        if(l == r) { tree[node] = a[l]; return; }
        int mid = (l+r)/2;
        build(a, node*2, l, mid);
        build(a, node*2+1, mid+1, r);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    void push(int node, int l, int r) {
        if(lazy[node] != 0) {
            tree[node] += lazy[node];
            if(l != r) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if(r < ql || l > qr) return -1e18;

        if(ql <= l && r <= qr) return tree[node];

        int mid = (l+r)/2;
        return max(query(node*2, l, mid, ql, qr),
                   query(node*2+1, mid+1, r, ql, qr));
    }
};


// 
struct SegTreeXor {
    int n;
    vector<int> tree, lazy;

    SegTreeXor(int n) : n(n) {
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void build(vector<int> &a, int node, int l, int r) {
        if(l == r) { tree[node] = a[l]; return; }
        int mid = (l+r)/2;
        build(a, node*2, l, mid);
        build(a, node*2+1, mid+1, r);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }

    void push(int node, int l, int r) {
        if(lazy[node]) {
            if((r - l + 1) % 2 == 1)
                tree[node] ^= lazy[node];

            if(l != r) {
                lazy[node*2] ^= lazy[node];
                lazy[node*2+1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);

        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            lazy[node] ^= val;
            push(node, l, r);
            return;
        }

        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if(r < ql || l > qr) return 0;
        if(ql <= l && r <= qr) return tree[node];

        int mid = (l+r)/2;
        return query(node*2, l, mid, ql, qr)
             ^ query(node*2+1, mid+1, r, ql, qr);
    }
};


// ❗ 5. Segment Tree for GCD (no real lazy!)

gcd on range = gcd(a[l], gcd(diff[l+1..r]))
diff[i] = a[i] - a[i-1]
