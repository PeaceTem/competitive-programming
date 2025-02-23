#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin>>n; vector<int> a(n),b(n);
    for(auto& it : a) cin>>it;
    for(auto& it : b) cin>>it;

    int mx = INT_MIN, total = 0, ind=-1;

    for(int i=0;i<n;i++){
        if(a[i]+b[i] > mx) ind = i, mx=a[i]+b[i];
    }

    total = mx;

    for(int i=0; i<n;i++){
        if(i==ind) continue;
        if(a[i]>b[i]) total += a[i];
        else total += b[i];
    }

    cout << total << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}