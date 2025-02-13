#include <bits/stdc++.h>
using namespace std;


void solve() {
    string x; cin>>x; int output = x.length();
    for(int i=0;i<output-1; i++){
        if(x[i] == x[i+1]) output = 1;
    }
    cout<<output<<'\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}