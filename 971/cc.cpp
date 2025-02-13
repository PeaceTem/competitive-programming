#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k; cin>>x>>y>>k; int ans;
    int x1 = x/k; int y1 = y/k;
    if(x%k != 0) x1++; if(y%k != 0) y1++;
    if(y1>=x1) ans = y1*2;
    else ans = x1*2 -1;
    cout << ans << '\n';
   
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}