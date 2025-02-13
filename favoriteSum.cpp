#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,x, sum=0, total =0; cin>>n>>x;
    
    total = x * (x+1LL) / 2;
    for (int i = 1; i <= n; i++) {
        long long fav; cin >> fav;
        if(fav <= x) total -= 2*fav;
    }

    cout << total << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}