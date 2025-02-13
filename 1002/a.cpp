#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, x; cin>>n; unordered_map<int, int> a,b;

    for(int i=0;i<n; i++){
        cin>>x; a[x]++;
    }

    for(int i=0;i<n; i++){
        cin>>x; b[x]++;
    }

    if(a.size() + b.size() >= 4) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}