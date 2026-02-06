// Rabin-Karp String Matching Algorithm

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull B = 131;  // base

vector<int> rabin_karp(const string& s, const string& pat) {
    int n = s.size(), m = pat.size();
    if(m > n) return {};

    // Precompute powers
    vector<ull> power(n+1);
    power[0] = 1;
    for(int i=1;i<=n;i++)
        power[i] = power[i-1] * B;

    // Prefix hash for s
    vector<ull> H(n+1, 0);
    for(int i=0;i<n;i++)
        H[i+1] = H[i] * B + s[i];

    // Hash of pattern
    ull Hpat = 0;
    for(char c : pat) Hpat = Hpat * B + c;

    // Find matches
    vector<int> res;
    for(int i=0;i + m <= n; i++){
        // hash of s[i..i+m-1]
        ull cur = H[i+m] - H[i] * power[m];
        if(cur == Hpat){
            // optional verification:
            if(s.compare(i, m, pat) == 0)
                res.push_back(i);   // starting index
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, pat;
    cin >> s >> pat;

    auto pos = rabin_karp(s, pat);
    for(int x : pos) cout << x << " ";
}


//----------------------------
// Manacher's Algorithm for Longest Palindromic Substring
//----------------------------

string longestPalindromeManacher(string s) {
    if (s.empty()) return "";

    // transform: add # between characters
    string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.size();
    vector<int> P(n, 0); // radius array
    int C = 0, R = 0;    // center, right boundary

    for (int i = 1; i < n - 1; i++) {
        int mir = 2 * C - i;

        if (i < R)
            P[i] = min(R - i, P[mir]);

        // expand
        while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;

        // move center
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // find max
    int maxLen = 0, center = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            center = i;
        }
    }

    int start = (center - maxLen) / 2;
    return s.substr(start, maxLen);
}



//---------------------------
// Longest Palindromic Subsequence (DP)
//---------------------------
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // build from shorter to longer substrings
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (s[i] == s[j])
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i+1][j-1]);
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int main(){
    string s; 
    cin >> s;
    cout << longestPalindromeSubseq(s);
}


//---------------------------
// Count of Palindromic Subsequences
// Given a string, count all distinct palindromic subsequences.
//---------------------------

#include <bits/stdc++.h>
using namespace std;

long long countPalindromicSubseq(string s) {
    int n = s.size();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // base case: single character
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // increasing substring length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            } else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    string s;
    cin >> s;
    cout << countPalindromicSubseq(s) << endl;
}


//---------------------------
// Count Subsequences of a String
// Given two strings s and t, count the number of distinct subsequences of s which equals t.
//---------------------------
#include <bits/stdc++.h>
using namespace std;

long long countSubseq(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

    // empty target can always be formed
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << countSubseq(s, t);
}

// Space Optimized Version

long long countSubseq(string s, string t) {
    int n = s.size(), m = t.size();
    vector<long long> dp(m+1, 0);

    dp[0] = 1;  // empty target

    for (char c : s) {
        for (int j = m-1; j >= 0; j--) {
            if (c == t[j])
                dp[j+1] += dp[j];
        }
    }

    return dp[m];
}



//---------------------------
// Minimum Insertions and Deletions to Transform String s to t
//---------------------------
#include <bits/stdc++.h>
using namespace std;

int LCS(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
    return dp[n][m];
}

cout << __builtin_popcount(n) <<< endl;

int main() {
    string s, t;
    cin >> s >> t;

    int L = LCS(s, t);
    int deletions = s.size() - L;
    int insertions = t.size() - L;

    cout << "Deletions: " << deletions << "\n";
    cout << "Insertions: " << insertions << "\n";
}

//---------------------------
// Edit Distance (Levenshtein Distance)
// Given two strings A and B, find the minimum number of operations required to convert A to B.
// Operations allowed: insert, delete, replace
//---------------------------

int minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    // Base cases
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],     // delete
                    dp[i][j-1],     // insert
                    dp[i-1][j-1]    // replace
                });
            }
        }
    }

    return dp[n][m];
}
