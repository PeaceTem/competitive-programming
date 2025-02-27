#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    int ab = n/15; int rem = n%15;
    
    int ans = ab * 3 + (min(rem,2) + 1);

    cout << ans << '\n';
}
int main(){
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t--) solve(); return 0;
}