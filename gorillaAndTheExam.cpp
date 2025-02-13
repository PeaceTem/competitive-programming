#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::vector<int> cnt = {1};
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cnt.back()++;
        } else {
            cnt.emplace_back(1);
        }
    }
    std::sort(cnt.begin(), cnt.end());
    int m = cnt.size();
    for (int i = 0; i < m - 1; i++) {
        if (cnt[i] > k) {
            std::cout << m - i << "\n";
            return;
        }
        k -= cnt[i];
    }
    std::cout << 1 << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}