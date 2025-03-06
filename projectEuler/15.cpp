#include <bits/stdc++.h>
using namespace std;

int paths = 0; int n=20;
void lattice(int x, int y){
    if(x==n && y==2) paths++;
    if(x<n) lattice(x+1,y);
    if(y<n) lattice(x,y+1);
}
void solve() {
    lattice(0,0);

    cout << paths << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}