#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

///////////////////////////////
// 1. SPARSE TABLE RMQ
///////////////////////////////
class SparseTable {
    vector<vector<int>> st; // st[i][j] stores the minimum in the interval starting at i with length 2^j
    vector<int> logTable;
    int n;
public:
    // Constructor: builds the sparse table from the input array "arr"
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        logTable.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }
        int K = logTable[n] + 1;
        st.assign(n, vector<int>(K));
        // Initialize intervals of length 1
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        // Compute values for intervals with length 2^j
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Returns the minimum value in the interval [L, R] (0-indexed)
    int query(int L, int R) {
        int j = logTable[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

///////////////////////////////
// 2. BLOCK-DECOMPOSITION RMQ (Hybrid / Fischer-Heun–inspired)
///////////////////////////////
class BlockRMQ {
    vector<int> arr;        // Copy of the input array
    int n;
    int blockSize;          // Typically a small value (for example, floor(log2(n)/2) or a fixed constant)
    int numBlocks;
    vector<int> blockMins;  // For each block, store the index (in arr) of the block's minimum element
    SparseTable *blockST;   // Sparse table built on the block minima (using arr values)

public:
    // Constructor: builds the block decomposition RMQ structure
    BlockRMQ(const vector<int>& input) {
        arr = input;
        n = arr.size();
        // Choose a block size. For many arrays a fixed small block size works well.
        // Here, we choose blockSize = max(1, floor(log2(n)/2))
        blockSize = max(1, (int)floor(log2(n) / 2.0));
        numBlocks = (n + blockSize - 1) / blockSize;
        blockMins.resize(numBlocks);

        // Compute the minimum for each block (store the index of the minimum element)
        for (int b = 0; b < numBlocks; b++) {
            int start = b * blockSize;
            int end = min(n, start + blockSize);
            int minIndex = start;
            for (int i = start; i < end; i++) {
                if (arr[i] < arr[minIndex])
                    minIndex = i;
            }
            blockMins[b] = minIndex;
        }
        // Build a sparse table on the block minima using the original arr values
        vector<int> blockMinValues;
        for (int b = 0; b < numBlocks; b++) {
            blockMinValues.push_back(arr[blockMins[b]]);
        }
        blockST = new SparseTable(blockMinValues);
    }

    ~BlockRMQ() {
        delete blockST;
    }

    // Query RMQ on the entire array for the interval [L, R] (0-indexed)
    // Returns the index in arr of the minimum element in [L, R]
    int query(int L, int R) {
        int bL = L / blockSize, bR = R / blockSize;
        int ansIndex = L; // initialize with L

        if (bL == bR) {
            // The query is contained in a single block; do a linear scan.
            for (int i = L + 1; i <= R; i++) {
                if (arr[i] < arr[ansIndex])
                    ansIndex = i;
            }
            return ansIndex;
        }
        // Process the left partial block
        int endLeft = (bL + 1) * blockSize;
        for (int i = L; i < endLeft; i++) {
            if (arr[i] < arr[ansIndex])
                ansIndex = i;
        }
        // Process the right partial block
        int startRight = bR * blockSize;
        for (int i = startRight; i <= R; i++) {
            if (arr[i] < arr[ansIndex])
                ansIndex = i;
        }
        // Process full blocks between bL+1 and bR-1 using the sparse table on block minima
        if (bL + 1 <= bR - 1) {
            int blockMinValue = blockST->query(bL + 1, bR - 1);
            // Find the block index that has that value.
            // (Because our blockST was built on blockMinValues, the value returned is the minimum value.)
            // We then compare with our current candidate.
            if (blockMinValue < arr[ansIndex]) {
                // We need to find the corresponding index in arr.
                // Scan the blocks between bL+1 and bR-1 to locate the block whose minimum equals blockMinValue.
                for (int b = bL + 1; b <= bR - 1; b++) {
                    if (arr[blockMins[b]] == blockMinValue) {
                        ansIndex = (arr[blockMins[b]] < arr[ansIndex]) ? blockMins[b] : ansIndex;
                        break;
                    }
                }
            }
        }
        return ansIndex;
    }
};

///////////////////////////////
// MAIN: Demonstration of both RMQ data structures
///////////////////////////////
int main() {
    // Sample array
    vector<int> arr = { 1, 3, 0, 2, 5, -1, 4, 7, 3, 2, 0, -2, 8, 9 };

    cout << "=== Sparse Table RMQ ===" << endl;
    {
        SparseTable st(arr);
        int L = 2, R = 11;
        int minValue = st.query(L, R);
        cout << "Minimum value in arr[" << L << ", " << R << "] is " << minValue << endl;
    }

    cout << "\n=== Block-Decomposition RMQ (Hybrid) ===" << endl;
    {
        BlockRMQ blockRMQ(arr);
        int L = 2, R = 11;
        int idx = blockRMQ.query(L, R);
        cout << "Minimum value in arr[" << L << ", " << R << "] is at index " << idx 
             << " with value " << arr[idx] << endl;
    }

    return 0;
}
