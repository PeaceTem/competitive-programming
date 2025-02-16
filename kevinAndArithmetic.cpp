#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,x; vector<int> a,b; cin>>n;
    for(int i=0; i<n;i++){
        cin>>x;
        if(x&1) b.push_back(x);
        else a.push_back(x);
    }

    if(a.size()>0) cout << 1 + b.size() << '\n';
    else cout << b.size() - 1 <<"\n";

}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) solve(); return 0;
}