#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n; vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n; i++){
        if(a[i] <= 2*max(abs(n-1-i), abs(i-0))){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}