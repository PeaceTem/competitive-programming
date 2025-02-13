#include <bits/stdc++.h>
using namespace std;


void solve() {
    string x; cin>>x;
    x.replace(x.length() - 2, 2, "i");
    cout<<x<<'\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}