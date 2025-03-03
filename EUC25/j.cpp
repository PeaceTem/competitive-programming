#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; cin>>n;
    string s; cin>>s; int r0=0,r1=0,w0=0,w1=0;

    for(int i=0;i<n;i++){
        if(s[i]=='W') w0++;
        else r0++;
    }
    if(w0&1){
        cout << "NO\n"; return;
    }
    int wk = w0/2;
    for(int i=0;i<wk;i++){
        if(s[i]=='R'){
            cout << "NO\n"; return;
        }
    }
    for(int i=2*n-wk;i<2*n;i++){
        if(s[i]=='W'){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}