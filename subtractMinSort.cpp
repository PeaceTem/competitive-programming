#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n; cin>>n; vector<int> a(n); int m;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n-1; i++){
        if(a[i] > a[i+1]){
            cout << "NO" << '\n';
            return;
        }
        m = min(a[i], a[i+1]);

        a[i] = a[i] -m; a[i+1] = a[i+1] -m;
    }
    cout << "YES" << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}