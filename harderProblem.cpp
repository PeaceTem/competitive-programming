#include <bits/stdc++.h>
using namespace std;
// copy the a into b;
// loop through b;
// find all the unique numbers in a;
// write them out sequentially
// fill the rest the dummy number <= n that are not in the list

void solve() {
    int n,x; cin>>n; vector<int> a; unordered_set<int> toRemove; vector<int> c;
    for(int i=0; i<n; i++){
        cin>>x;
        if(toRemove.count(x) == 0){
            toRemove.insert(x);
            c.push_back(x);
        }
    }
    // Construct vector with numbers from 1 to n.

    for (int i = 1; i <= n; ++i) {
        if(toRemove.count(i)==0) a.push_back(i);
    }
    
    for(int& num : c) cout << num << ' ';
    for(int& num : a) cout << num << ' ';

    cout << '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}