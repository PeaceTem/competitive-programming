#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin>>n>>k;
    if(k==1 || n==k){
        for(int i=1;i<=n;i++) cout << i << ' ';
        cout << '\n'; return;
    }
    int _u; int u = _u = n/k;
    vector<int> v(n);
    for(int i=0;i+u<n;i++) v[i] = ++_u;

    int p1=0,p2=1;
    for(int i=0;i+u<n;i++){
        p1++;
        if(p1%k==0){
            cout << p2 << ' '; p1++;p2++;
        }
        cout << v[i] << ' ';
    }
    if(p2==u) cout << p2;
    cout << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}