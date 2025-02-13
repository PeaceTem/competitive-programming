#include <bits/stdc++.h>

using i64 = long long;
using namespace std;



void solve() {
    string word; cin>>word;

    if(word.length() <= 10){
        cout << word << "\n";
    } else {
        cout << word.front() << word.length() -2 << word.back() << "\n";
    }
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