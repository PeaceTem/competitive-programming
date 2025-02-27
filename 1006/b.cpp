#include <bits/stdc++.h>
using namespace std;


// for (int &x : a) cin >> x;


void solve(){
    int n; cin>>n; vector<char> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long b=0,c=0;
    for(int i=0;i<n;i++){
        if(a[i]=='-') b++;
        else c++;
    }

    if(b<2 || c<1){
        cout << 0 << '\n';
        return;
    }

    long long result = b%2 ? (b/2)*(b/2 + 1)*c : ((b/2)*(b/2))*c;
    cout << result << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}