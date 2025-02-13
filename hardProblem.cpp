#include <bits/stdc++.h>
using namespace std;


void solve() {
    int m, a,b,c; cin>>m>>a>>b>>c;
    int _a = a<=m? a: m;
    int _b = b<=m? b: m;
    int _c = c<=(2*m - _a - _b) ? c : (2*m - _a - _b);
    cout << _a + _b + _c << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}