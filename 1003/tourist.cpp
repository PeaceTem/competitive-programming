#include <bits/stdc++.h>
using namespace std;


void solve() {
    vector<int> a(3);
    iota(a.begin(), a.end(), 0);

    int n; cin>>n; int x; cin>>x;
    int ans = a[x];
    n%=6;
    for(int i=n;i>0;i--){
        if(i&1) swap(a[0],a[1]);
        else swap(a[1],a[2]);
    }
    cout << (find(a.begin(),a.end(),x) - a.begin())<< '\n';
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}