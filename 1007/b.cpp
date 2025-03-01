#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n; cin>>n;
	ll t = n*(n+1LL) / 2LL;
	ll sq = sqrt(t);

	if(sq*sq == t){
		cout << -1 << '\n';
		return;
	}

	ll l = 1LL, r = n;
	while(l<=r){
		if(l==r) cout << l << ' ';
		else {
			cout << r << ' ' << l << ' ';
		}
		--r;++l;
	}

	cout << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}