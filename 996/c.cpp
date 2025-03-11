#include <bits/stdc++.h>


using namespace std;
#define ll long long

void solve(){
    ll n, m; cin>>n>>m;
    string s; cin>>s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) cin>>a[i][j];
    }
    // make the sum of each row and each col be 0;
    pair<ll, ll> pos ={0,0};
    for(ll i=0;i<n+m-2;i++){
        if(s[i]=='D'){
            ll sm = accumulate(a[pos.first].begin(), a[pos.first].end(), 0LL);
            a[pos.first][pos.second] = 0 - sm;
            pos.first++;
        } else {
            ll sm =0;
            for(ll i=0;i<n;i++) sm += a[i][pos.second];
            a[pos.first][pos.second] = 0 - sm;
            pos.second++;
        }
    }

    ll sm =accumulate(a[n-1].begin(), a[n-1].end(), 0);
    a[n-1][m-1] = 0 - sm;


    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>>t; while(t--) solve(); return 0;
}
    