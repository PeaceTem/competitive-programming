#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin>>n>>m; int count = 0; vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
    for(int i=0; i<n; i++){
        sort(a[i].begin(), a[i].end(), [&](const int& x, const int& y){return x < y;});
    }

    // Indices vector to be affected by the sort
    std::vector<int> indices(a.size());
    
    // Initialize indices with 0, 1, 2, ...
    for (int i = 0; i < indices.size(); i++) {
        indices[i] = i;
    }

    // Sort based on values, and update indices accordingly
    std::sort(indices.begin(), indices.end(), [&](int i, int j) {
        return a[i][0] < a[j][0];
    });

    // Reorder `values` based on the sorted indices
    std::vector<std::vector<int>> s_a(a.size());
    for (int i = 0; i < a.size(); i++) {
        s_a[i] = a[indices[i]];
    }

    for(int i=n; i<n*m; i++){
        if(s_a[i%n][i/n] < s_a[(i-1)%n][(i-1)/n]){
            cout << "-1\n";
            return;
        };

    }
    for(int i=0; i<n; i++) cout << indices[i] + 1 << ' ';
    cout << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}