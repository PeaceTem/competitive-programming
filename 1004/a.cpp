#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b; cin>>a>>b;
    
    if((a%9==0 && b==1) || (a+1 == b) || (((a-8-b)%9 == 0) && (a-8-b >= 0))) cout << "YES" << '\n';
    else cout << "No" << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}