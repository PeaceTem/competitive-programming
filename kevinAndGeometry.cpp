#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; vector<int> a(n);
    map<int, int> b; int c =0; int x;

    for(int i=0; i<n; i++){
        cin>>x;
        b[x]++;
        if(b[x]==2) c=x;
    }
    vector<int> ans; int c_c = 0;

    if(c>0){
        int rem =2;
        ans.push_back(c); ans.push_back(c); b[c] -=2;
        for(const auto &e : b){
            for(int i=0; i<min(rem, e.second); i++){
                ans.push_back(e.first);
                rem--;
            }
            if(rem==0) break;
        }
        for(int k : ans) cout << k << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t-->0) solve(); return 0;
}