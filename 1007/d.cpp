#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; ll l,r; cin>>n>>l>>r; vector<int> a(n), b(2*n);
	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=0;i<n;i++){
		b[i] = a[i];
	}
	b[n] = a[0];
	for(int i=1;i<=(n)/2;i++) a[0] ^= a[i];
	for(int i=1;i<n;i++) a[0] ^= a[i];
	
	for(int i=n;i<2*n;i++){
		b[i] = b[i] ^ b[i-1];
	}
	int c = 0; int p =0;
	if(l<=2*n){
		cout << b[l-1] << '\n'; return;
	}
	bool odd = l&1;
	while(l>2*n){
		l /= 2LL;
	}



	if(odd) cout << a[0] << '\n';
	else cout << (a[0] ^ b[l-1]) << '\n';

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}