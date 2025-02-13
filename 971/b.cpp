#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a; char x;

    for(int i=0; i<n; i++){
        for(int j = 1; j<5 ; j++){
            cin>>x;
            if(x == '#') a.push_back(j);
        }
    }

    reverse(a.begin(), a.end());
    for(int b : a) cout << b << ' ';
    cout << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}