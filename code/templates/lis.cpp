//---------------------------
// Longest Increasing Subsequence with Maximum Sum
// Given an array of integers, find the sum of the longest increasing subsequence.
//---------------------------


#include <bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = a[i];  // subsequence containing only a[i]
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << maxSumIS(a);
}



//---------------------------
// Maximum Subarray Sum (Kadane's Algorithm)
// Given an array of integers, find the contiguous subarray with the largest sum.
//---------------------------
int maxSubArray(vector<int>& a) {
    int cur = a[0];
    int best = a[0];

    for (int i = 1; i < a.size(); i++) {
        cur = max(a[i], cur + a[i]);
        best = max(best, cur);
    }

    return best;
}
