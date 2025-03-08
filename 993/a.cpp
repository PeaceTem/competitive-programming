#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long


void solve(){
    string s; cin>>s;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == 'q') cout << 'p';
        else if(s[i] == 'p') cout << 'q';
        else cout << s[i];
    }
    cout << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; std::cin >> t; while (t--) solve(); return 0;
}