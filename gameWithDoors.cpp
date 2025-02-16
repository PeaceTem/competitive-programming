#include <bits/stdc++.h>

using namespace std;


void solve(){
    int x,x1,y,y1; cin>>x>>y>>x1>>y1;
    if(x>y1 or x1>y) cout << 1 << '\n';
    else if(x==x1 and y==y1) cout << y-x << '\n';
    else if(x==x1 or y==y1)  cout << 1 + max(0, min(y,y1) - max(x,x1)) << '\n';
    else cout << 2 + max(0, min(y,y1) - max(x,x1)) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) solve(); return 0;
}