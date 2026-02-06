//---------------------------
// Balloon Shooting Problem
// Given n balloons represented as intervals [l, r],
// find the minimum number of arrows required to burst all balloons.
//---------------------------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if(!(cin >> n)) return 0;
    vector<pair<ll,ll>> a;
    a.reserve(n);
    for(int i=0;i<n;i++){
        ll l,r; cin >> l >> r;
        if(l > r) swap(l,r);
        a.emplace_back(r,l); // store as (end,start) to ease sort
    }

    sort(a.begin(), a.end()); // sorted by end, then start

    ll arrows = 0;
    ll cur_end = LLONG_MIN; // position of last arrow
    for(auto &p : a){
        ll end = p.first;
        ll start = p.second;
        if(start > cur_end){
            arrows++;
            cur_end = end; // place arrow at this balloon's right endpoint
        }
    }

    cout << arrows << '\n';
    return 0;
}


//---------------------------
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.
//---------------------------

int trap(vector<int>& h) {
    int n = h.size();
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while(l < r) {
        if(h[l] < h[r]) {
            if(h[l] >= leftMax)
                leftMax = h[l];
            else
                ans += leftMax - h[l];
            l++;
        } 
        else {
            if(h[r] >= rightMax)
                rightMax = h[r];
            else
                ans += rightMax - h[r];
            r--;
        }
    }

    return ans;
}


//---------------------------
// Minimum Window Substring
// Given two strings s and t, find the minimum window in s which will contain all the characters in t.
// If there is no such window in s that covers all characters in t, return the empty
//---------------------------

string minWindow(string s, string t) {
    if(t.size() > s.size()) return "";

    vector<int> need(128, 0), have(128, 0);

    for(char c : t) need[c]++;

    int required = 0;
    for(int i = 0; i < 128; i++)
        if(need[i] > 0) required++;

    int formed = 0;

    int l = 0, r = 0;
    int bestLen = INT_MAX;
    int bestL = 0;

    while(r < s.size()) {
        char c = s[r];
        have[c]++;

        if(have[c] == need[c] && need[c] > 0)
            formed++;

        while(formed == required) {
            // update answer
            if(r - l + 1 < bestLen) {
                bestLen = r - l + 1;
                bestL = l;
            }

            // try shrinking
            char leftChar = s[l];
            have[leftChar]--;

            if(have[leftChar] < need[leftChar] && need[leftChar] > 0)
                formed--;

            l++;
        }

        r++;
    }

    return (bestLen == INT_MAX ? "" : s.substr(bestL, bestLen));
}
