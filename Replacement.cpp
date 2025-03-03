#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s,r; cin>>s>>r; bool alt = true;
    int s0=0,s1=0,r0=0,r1=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') s1++;
        else s0++;
    }
    for(int i=0;i<n-1;i++){
        if(r[i]=='1') r1++;
        else r0++;
    }

    if(r.back()=='0') r0--;
    else r1--;


    if(s0==r1+1 && s1==r0+1) cout << "YES\n";
    else cout << "NO\n";
    
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}