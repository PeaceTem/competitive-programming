#include <bits/stdc++.h>
using namespace std;

void solve() {
    string n; cin>>n;

    if(n[0] == n[2]) n[1] ='=';
    else if(n[0]<n[2]) n[1] = '<';
    else n[1] = '>';

    cout << n << '\n';

}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}