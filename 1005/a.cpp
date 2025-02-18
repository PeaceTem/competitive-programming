#include <bits/stdc++.h>
using namespace std;


// for (int &x : a) cin >> x;


void solve(){
    int n; cin>>n;
	string x; cin >> x; int ct = 0, res=0;
	for(int i=0; i<n; i++){
		if(x[i] == '1'){
			if(i == n -1) res += 1;
			ct++;
		} else {
			if(ct > 0) res += 2;
			ct = 0;
		} 
	}

	cout << res << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}