#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n; cin>>n; int count = 0;
    for(char c: n){
        if(c == '1') count++;
    }

    cout << count << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}