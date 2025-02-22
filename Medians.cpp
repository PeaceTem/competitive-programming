#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    int l=k-1, r=n-k;

    // if(l%2 != r%2){
    //     cout << -1 << '\n'; return;
    // }

    if(l==0 and r==0){
        cout << 1 << '\n';
        cout << k << '\n'; return;
    } else if(l&1 and r&1){
        cout << 3 << '\n';
        cout << 1 << " " << k << " " << k+1 << '\n'; return;
    } else if((l%2==0 and r%2==0) and (r!=0 and l!=0)){
        cout << 5 << '\n';
        cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << k+2 << '\n'; return;
    }

    cout << -1 << '\n'; return;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}