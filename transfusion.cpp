#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin>>n; vector<int> a, b;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        if(i%2) a.push_back(x);
        else b.push_back(x);
    }
    double odd = (double) accumulate(a.begin(), a.end(), 0)/a.size();
    double even = (double) accumulate(b.begin(), b.end(), 0)/b.size();
    if(odd == even &&   floor(odd) == odd) cout << "YES\n";
    else cout << "NO\n";

}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}