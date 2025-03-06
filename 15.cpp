#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 20, t=1;
    for(int i=n;i>0;i--){
        t=i>1? t*2:t*3;
    }

    cout << t << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}