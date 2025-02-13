#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    if(n==1) cout << "1\n";
    else if(n<=4) cout << "2\n";
    else {
        int count = 2, i=4;
        while(n > i){
            i = i*2 + 2;
            count++;
        }
        cout << count << '\n';
    }
    
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}