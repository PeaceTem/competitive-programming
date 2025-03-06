#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long


const int maxn = 42;
ull C[maxn + 1][maxn + 1];
void combination(){
    C[0][0]=1;
    for(ull n=1; n<=maxn;n++){
        C[n][n] = c[n][0] = 1;
        for(ull k=1;k<n;k++){
            C[n][k] = C[n-1][k-1] + C[n-1][k];
        }
    }
}


void solve() {
    combination();
    ull paths = C[40][20];

    cout << paths << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}