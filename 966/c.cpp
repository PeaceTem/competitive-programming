#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a(n);
    for(auto& it : a) cin>>it;
    int m; cin>>m;
    vector<string> b(m);
    for(auto& it : b) cin>>it;
    map<int, set<int>> ma; map<char, set<int>> mb;
    for(int i=0;i<n;i++){
        ma[a[i]].insert(i);
    }

    for(int i=0;i<m;i++){
        if(b[i].length() != n){
            cout << "NO\n"; continue;
        }
        for(int j=0;j<n;j++) mb[b[i][j]].insert(j);
        vector<int> diff;

        for(auto& it : mb){
            int x = a[*it.second.begin()];
            set_symmetric_difference(it.second.begin(), it.second.end(),
                                ma[x].begin(), ma[x].end(), back_inserter(diff));

        }
        mb.clear();
        if(diff.size()>0){
            // for(int num : diff) cout << num << ' ';
            cout << "NO\n";
        } else cout << "YES\n";
    }
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}