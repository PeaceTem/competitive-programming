#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; ll l,r; cin>>n>>l>>r; vector<int> a(n), b(n);
	for(int i=0;i<n;i++) cin >> a[i];
	// b[0] = a[0];
	// for(int i=1;i<n;i++){
	// 	b[i] = a[i] ^ b[i-1];
	// }
	int c = 0;
	while(l>n){
		l /= 2LL;
		if(l%2 == 1) c++;
	}

	cout << (a[l] + c)%2 << '\n';
    
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}