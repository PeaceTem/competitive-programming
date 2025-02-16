#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k; vector<int> a(n);
    for(auto &it : a) cin>>it;

    if(n==k){
        for(int i=1; i<n;i+=2){
            if(a[i] != (i+1)/2){

            cout << (i+1)/2 << '\n';
            return;
            }
        }

        cout << n/2 + 1 << '\n';
        return;
    }

    int r = n-k + 1;
    for(int i=1; i<=r;i++){
        if(a[i] != 1){
            cout << "1\n";
            return;
        }
    }

    cout << "2\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}