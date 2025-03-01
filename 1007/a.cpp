#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin>>n;
    int m = n%3;
	if(m == 1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}