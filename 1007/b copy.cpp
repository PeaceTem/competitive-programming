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
	ll temp = 0;
	for(ll i=1;i<=n;i++){
		
		ll x = i*(i+1LL) / 2LL;
		ll s = sqrt(x);
		if(s*s == x) temp = i;
		if(temp > 0){
			if(i == temp) continue;
			cout << i << ' ' << temp << ' '; temp =0;
		} else {
			cout << i << ' ';
		}

	}

	cout << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}