#include <bits/stdc++.h>
using namespace std;


// for (int &x : a) cin >> x;


void solve(){
    int n,k,q; cin>>n>>k>>q;
    int m = abs(k)/q;
    if(abs(k)%q!=0) m++;

    if(m>n){
        cout << -1 << '\n';
        return;
    }

    cout << m << '\n';

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}