#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n,0), c(n,0); char x; 
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cin>>x;
            if(x=='1'){
                // a[i] += 1;
                if(i<j) c[i] += 1;
            }
        }
    }

    vector<int> d(n);
    for(int i=0;i<n;i++){
        d[i] = abs(c[i] - a[i]);
    }
    // for(int num : d) cout << num << ' ';
    // cout << '\n';
    // cout << "Working!\n";
    vector<int> b(n, 0);
    iota(b.begin(), b.end(),1);
    sort(b.begin(),b.end(),[&](int i,int j){
        if(c[i-1] != c[j-1]) return c[i-1] > c[j-1];
        else return i > j;
    });

    for(int num : b) cout << num << ' ';
    cout << '\n';
    
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}
